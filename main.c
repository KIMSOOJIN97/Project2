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
	stat("text1",&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	stat("text2",&stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	printf("text1\n");
	time_1=localtime(&stat1.st_mtime);
	printf("size : %d\n", (int)stat1.st_size);
	printf("blocks : %d\n", (int)stat1.st_blocks);
	printf("month : %d\n", time_1->tm_mon+1);
	printf("date : %d\n", time_1->tm_mday);	
	printf("hour : %d\n", time_1->tm_hour);
	printf("min : %d\n", time_1->tm_min);
}


//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	printf("text2\n");
	time_2 = localtime(&stat2.st_mtime);
    	printf("size : %d\n", (int)stat2.st_size);
	printf("blocks : %d\n", (int)stat2.st_blocks);
	printf("month : %d\n", time_2->tm_mon+1);
	printf("date : %d\n", time_2->tm_mday);
	printf("hour : %d\n", time_2->tm_hour);
	printf("min : %d\n", time_2->tm_min);

}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){

	int s1 = (int)stat1.st_size;
	int s2 = (int)stat2.st_size;

	printf("size compare\n");

	if(s1 > s2)	printf("text1 is bigger\n");
	else if (s1 < s2)	printf("text2 is bigger\n");
	else 			printf("same size\n");
		
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    int block1 = (int)stat1.st_blocks;
    int block2 = (int)stat2.st_blocks;
    printf("block compare\n");

    if(block1 > block2)	printf("text1 is bigger\n");
    else if(block1<block2)	printf("text2 is bigger\n");
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