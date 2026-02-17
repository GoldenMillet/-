#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESS_VAL 10

// 全局通用寄存器，真实情况在CPU中
int AX = 0, BX = 0, CX = 0, DX = 0;
int PC = 0;
int PSW = 0;

// 进程控制块PCB
enum state {OKAY, WAIT};
struct PCB {

	// 进程编号
	int setName;
	int name;

	// 进程状态
	enum state status;

	// 寄存器
	int ax, bx, cx, dx;
	int pc;
	int psw;

	// 类似链表，下一个进程块编号
	int next;
};

PCB PCBarea[MAX_PROCESS_VAL];   // PCB总队列
int pFree = 0;      		 // 表示PCB总队列的状态

// PCB空闲队列
struct ready {
	int head;
	int tail;

	// 默认构造函数
	ready() : head(0), tail(0) { }
};
PCB PCBwait[MAX_PROCESS_VAL];		// PCB等待队列
ready readyQ;
int pRun;				// 当前正在运行的进程

// 相关函数
bool createProcess(const int iset, const int iname, const enum state istate){
	
	// 判断是否有控制块冗余
	if((pFree < 0) || (pFree >= MAX_PROCESS_VAL)) return false;

	// 填写PCB块
	PCBarea[pFree].setName = iset;
	PCBarea[pFree].name = iname;
	PCBarea[pFree].status = istate;
	PCBarea[pFree].ax = PCBarea[pFree].bx = PCBarea[pFree].cx = PCBarea[pFree].dx = PCBarea[pFree].pc = PCBarea[pFree].psw = 0;
	PCBarea[pFree].next = -1;
	pFree++;

	// 加入队列
	if(readyQ.head == readyQ.tail){
		PCBwait[readyQ.tail] = PCBarea[pFree - 1];
		readyQ.tail = (readyQ.tail + 1) % MAX_PROCESS_VAL;
	} else if ((readyQ.tail + 1) % MAX_PROCESS_VAL == readyQ.head){
		return false;
	} else {
		PCBwait[readyQ.tail] = PCBarea[pFree - 1];
		readyQ.tail = (readyQ.tail + 1) % MAX_PROCESS_VAL;	
	}

	return true;	
}

bool schedule(){
	PCB buf;

	// 获取第一个进程
	if(readyQ.tail == readyQ.head) return false;
	else {
		buf = PCBwait[readyQ.head];
	}

	// 将CPU资源分配给u该进程
	pRun = buf.name;
	AX = buf.ax;
	BX = buf.bx;
	CX = buf.cx;
	DX = buf.dx;
	PC = buf.pc;
	PSW = buf.psw;
	
	// 统计一共有多少个进程组和多少个进程
	int arrayBuf[MAX_PROCESS_VAL] = {0};
	if(readyQ.head < readyQ.tail){
		for (int i = readyQ.head; i < readyQ.tail; i++){
			arrayBuf[PCBwait[i].setName]++;
		}
	} else {
		// 暂时无需考虑这种情况
	}

	// 统计当前进程要执行多长时间
	int setNum = 0;
	for(int i = 0; i < MAX_PROCESS_VAL; i++){
		printf("%d\t", arrayBuf[i]);
		if(arrayBuf[i] != 0){
			setNum++;
		}
	}

	// 执行进程
	printf("当前正在执行进程%d，其属于进程组%d，一共分配%d的CPU资源\n", buf.name, buf.setName, 100 / setNum / arrayBuf[buf.setName]);

	// 丢弃进程
	readyQ.head = (readyQ.head + 1) % MAX_PROCESS_VAL;

	return true;
}

int main(){

	// 增加创建进程
	if(!createProcess(1, 114514, OKAY)) exit(-1);
	if(!createProcess(1, 1, OKAY)) exit(-1);
	if(!createProcess(1, 2, OKAY)) exit(-1);
	if(!createProcess(2, 3, OKAY)) exit(-1);
	if(!createProcess(2, 4, OKAY)) exit(-1);

	// 调度
	while(readyQ.head != readyQ.tail){
		if(!schedule()) exit(-1);
	}

	return 0;

}
