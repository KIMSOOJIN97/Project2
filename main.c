#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){

	int size1 = (int)stat1.st_size;
	int size2 = (int)stat2.st_size;

	printf("size compare\n");

	if(size1 > size2)	printf("text1 is bigger\n");
	else if (size1 < size2)	printf("text2 is bigger\n");
	else 			printf("same size\n");
		
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    int blk1 = (int)stat1.st_blocks;
    int blk2 = (int)stat2.st_blocks;
    printf("block compare\n");

    if(blk1 > blk2)	printf("text1 is bigger\n");
    else if(blk1<blk2)	printf("text2 is bigger\n");
    else		printf("same number of block \n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
	int year1,year2;
    int mon1,mon2;
    int day1, day2;

    time1 =localtime(&stat1.st_mtime);
    time2 =localtime(&stat2.st_mtime);

    year1 = time1->tm_year;
    year2 = time2->tm_year;

    mon1 = time1->tm_mon;
    mon2 = time2->tm_mon;

    day1= time1->tm_mday;
    day2= time2->tm_mday;

    printF("date compare");

    if(year1 < year2)		printf("text1 is early\n");
    else if(year1 > year2)	printf("text2 is early\n");

    else{
	   if(mon1 > mon2)	printf("text1 is early\n");
	   else if(mon1 < mon2)      printf("text2 is early\n");
	   else{
		   if(day1 > day2)           printf("text1 is early\n");
		   else if(day1 < day2)      printf("text2 is early\n");
		   else		printf("same date\n");
	   }
    }
}


//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    int hour1, hour2;
    int min1, min2;
    int sec1, sec2;

    time1 =localtime(&stat1.st_mtime);
    time2 =localtime(&stat2.st_mtime);
    
    hour1 = time1->tm_hour;
    hour2 = time2->tm_hour;

    min1 = time1->tm_min;
    min2 = time2->tm_min;

    sec1= time1->tm_sec;
    sec2= time2->tm_sec;

    printf( "time compare\n");

    if(hour1 < hour2)           printf("text1 is early\n");
    else if(hour1 > hour2)      printf("text2 is early\n");

    else{
           if(min1 > min2)      printf("text1 is early\n");
           else if(min1 < min2)      printf("text2 is early\n");
           else{
                   if(sec1 > sec2)           printf("text1 is early\n");
                   else if(sec1 < sec2)      printf("text2 is early\n");
                   else         printf("same time\n");
           }
    }   
}

