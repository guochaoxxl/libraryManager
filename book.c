#include "book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct _book{
	int bookNum;												//图书编号
	char bookName[NameSize];									//图书名称
	char bookISBN[ISBNSize];									//图书ISBN
	char bookAuthor[AuthorSize];								//图书作者
	char bookPress[PressSize];									//图书出版社
	float bookPrice;											//图书价格
	int bookStock;												//图书存量
} Book;*/

//信息输入
void inBookInfo(Book *ptrBook){
	//Book *ptrBook = (Book *)malloc(sizeof(Book));
	printf("请输入图书编号： ");
	scanf("%d", &ptrBook->bookNum);
	printf("请输入图书名称： ");
	scanf("%s", ptrBook->bookName);
	printf("请输入图书ISBN： ");
	scanf("%s", ptrBook->bookISBN);
	printf("请输入图书作者： ");
	scanf("%s", ptrBook->bookAuthor);
	printf("请输入图书出版社： ");
	scanf("%s", ptrBook->bookPress);
	printf("请输入图书价格： ");
	scanf("%f", &ptrBook->bookPrice);
	printf("请输入图书存量： ");
	scanf("%d", &ptrBook->bookStock);

	return;
} 

//打开文件创建
FILE *fopenC(char* fileName){
	//FILE *fp = fopen("fileBook.txt", "a");
	FILE *fp = fopen(fileName, "a");
	if(NULL == fp){
		printf("文件创建失败！");
		return NULL;
	}

	return fp;
} 

//打开文件读取
FILE *fopenR(char* fileName){
	//FILE *fp = fopen("fileBook.txt", "a");
	FILE *fp = fopen(fileName, "r");
	if(NULL == fp){
		printf("文件读取失败！");
		return NULL;
	}

	return fp;
} 

//打开文件写入
FILE *fopenW(char* fileName){
	FILE *fp = fopen(fileName, "w");
	if(NULL == fp){
		printf("文件写入失败！");
		return NULL;
	}

	return fp;
} 

//读入文件
void readBookInfo(char *fileName, Book *ptrBook){
	FILE *fp = fopen(fileName, "r");
	fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);

	return;
}

//写入文件 //信息固化
void writeBookInfo(char *fileName, Book *ptrBook){
	FILE *fp = fopen(fileName, "w");
	fprintf(fp, "\n%d\t%s\t%s\t%s\t%s\t%f\t%d", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);
	fclose(fp);

	return;
}

//显示文件
void outBookInfo(Book *ptrBook){
	printf("编号：%d\t 名称：%s\t ISBN：%s\t 作者：%s\t 出版社：%s\t 价格：%f\t 存量：%d\n", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);

	return;
}

//显示所有图书信息
void dispBookInfo(char *fileName){
	FILE *fp = fopen(fileName, "r");
	while(!feof(fp)){
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		printf("图书信息：编号：%d\t 名称：%s\t ISBN：%s\t 作者：%s\t 出版社：%s\t 价格：%f\t 存量：%d\n", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);
		getchar();
		fclose(fp);
	}

	return;
}

//图书查找-按编号
Book *findBookByNum(int bookNum, char *fileName){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	FILE *fp = fopen(fileName, "r");
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(ptrBook->bookNum == bookNum){
			return ptrBook;
		}
	}

	return NULL;
}

//图书查找-按作者
Book *findBookByAuthor(char *bookAuthor, char *fileName){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	FILE *fp = fopen(fileName, "r");
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(strcmp(ptrBook->bookAuthor, bookAuthor) == 0){
			return ptrBook;
		}
	}

	return NULL;
}

//图书查找-按ISBN
Book *findBookByISBN(char *bookISBN, char *fileName){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	FILE *fp = fopen(fileName, "r");
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(strcmp(ptrBook->bookISBN, bookISBN) == 0){
			return ptrBook;
		}
	}

	return NULL;
}

//添加图书
void addBook(){
	char select = 'n';
	do{
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		//创建图书文件
		inBookInfo(ptrBook);
		printf("\n刚刚添加的%s信息：\n", ptrBook->bookName);
		outBookInfo(ptrBook);
		inBookInfo(ptrBook);

		printf("\n是否继续添加图书，按y键继续, n键退出: ");
		scanf("%c", &select);

	}while('y' == select);
	dispBookInfo("bookFile.txt");
	getchar();
	//添加图书信息
	//将图书信息写入文件
	//inBookInfoFile("bookFile.txt", bookPtr);
	//显示添加后的所有图书文件
	//outBookInfo("bookFile.txt");

	return;
}

//删除图书
void deleBookByNum(){
	//打开图书文件读
	FILE *fpR = fopenR("bookFile.txt");
	//打开图书文件写
	FILE *fpW = fopenW("bookFileTmp.txt");
	int flag = 1;
	int bookNum;
	printf("请输入要删除的图书的编号：");
	scanf("%d", &bookNum);
	while(!feof(fpR)){
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		readBookInfo("bookFile.txt", ptrBook);
		if(findBookByNum(bookNum, "bookFile.txt") != NULL){
			flag = 0;
			continue;
		}

		writeBookInfo("bookFileTmp.txt", ptrBook);
	}
	if(flag){
		printf("您输入编号的图书不存在，按下任意键继续！\n");
		getchar();
	}else{
		printf("您输入编号的图书已删除，按下任意键继续！\n");
		getchar();
		getchar();
	}

	fclose(fpR);
	fclose(fpW);

	remove("bookFile.txt");
	rename("bookFileTmp.txt", "bookFile.txt");

	dispBookInfo("bookFile.txt");

	return;
}

//编辑图书
void editBook(){
	//打开图书文件读
	FILE *fpR = fopenR("bookFile.txt");
	//打开图书文件写
	FILE *fpW = fopenW("bookFileTmp.txt");
	int flag = 1;
	int bookNum;
	printf("请输入要修改的图书的编号：");
	scanf("%d", &bookNum);
	while(!feof(fpR)){
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		readBookInfo("bookFile.txt", ptrBook);
		if(findBookByNum(bookNum, "bookFile.txt") != NULL){
			printf("请输入图书编号： ");
			scanf("%d", &ptrBook->bookNum);
			printf("请输入图书名称： ");
			scanf("%s", ptrBook->bookName);
			printf("请输入图书ISBN： ");
			scanf("%s", ptrBook->bookISBN);
			printf("请输入图书作者： ");
			scanf("%s", ptrBook->bookAuthor);
			printf("请输入图书出版社： ");
			scanf("%s", ptrBook->bookPress);
			printf("请输入图书价格： ");
			scanf("%f", &ptrBook->bookPrice);
			printf("请输入图书存量： ");
			scanf("%d", &ptrBook->bookStock);
			
			flag = 0;
			writeBookInfo("bookFile.txt", ptrBook);
		}

		writeBookInfo("bookFile.txt", ptrBook);
	}
	if(flag){
		printf("您输入编号的图书不存在，按下任意键继续！\n");
		getchar();
	}else{
		printf("您输入编号的图书已修改，按下任意键继续！\n");
		getchar();
		getchar();
	}

	fclose(fpR);
	fclose(fpW);

	remove("bookFile.txt");
	rename("bookFileTmp.txt", "bookFile.txt");

	dispBookInfo("bookFile.txt");

	return;
}

//查找图书
void findBook(){

}

//查找子菜单
void menuBookFind(){
	int selectNum;
	do{
		system("clear");
		printf("	|--------------------------------------------------------------------|\n");
		printf("	|                           欢迎进入图书查找菜单                     |\n");
		printf("	|--------------------------------------------------------------------|\n");
		printf("	|                           1、---按编号查找---                      |\n");
		printf("	|                           2、---按作者查找---                      |\n");
		printf("	|                           3、---按ISBN查找---                      |\n");
		printf("	|                           4、---返回到上层---                      |\n");
		printf("	|--------------------------------------------------------------------|\n");
		printf("请根据菜单选择对应的编号(1~~4): ");
		scanf("%d", &selectNum);

		switch(selectNum){
			case 1:
				{
					int bookNum;
					printf("请输入要查找的编号：");
					scanf("%d", &bookNum);
					findBookByNum(bookNum, "bookFile.txt");

				}
				break;

			case 2:
				{
					char *bookAuthor = (char *)malloc(sizeof(char) * 30);
					printf("请输入要图书的作者：");
					scanf("%s", bookAuthor);
					findBookByAuthor(bookAuthor, "bookFile.txt");
				}
				break;

			case 3:
				{
					char *bookISBN = (char *)malloc(sizeof(char) * 30);
					printf("请输入要查找的ISBN：");
					scanf("%s", bookISBN);
					findBookByISBN(bookISBN, "bookFile.txt");
				}
				break;

			case 4:
				menuBook();
				break;

			default:
				printf("\n %d是非法输入，按下回车后请务必重新输入！\n", selectNum);
		}
	}while(1);

	return;
}

//图书菜单
void menuBook(){
	int selectNum;
	do{
		system("clear");
		printf("	|--------------------------------------------------------------------|\n");
		printf("	|                           欢迎进入图书管理模块                     |\n");
		printf("	|--------------------------------------------------------------------|\n");
		printf("	|                            1、---添加图书---                       |\n");
		printf("	|                            2、---删除图找---                       |\n");
		printf("	|                            3、---修改图书---                       |\n");
		printf("	|                            4、---查询图书---                       |\n");
		printf("	|                            5、---返回上层---                       |\n");
		printf("	|--------------------------------------------------------------------|\n");
		printf("请根据菜单选择对应的编号(1~~5): ");
		scanf("%d", &selectNum);
		switch(selectNum){
			case 1:
				addBook();
				break;

			case 2:
				deleBookByNum();
				break;

			case 3:
				editBook();
				break;

			case 4:
				menuBookFind();
				break;

			case 5:
				exit(0);
				//return;

			default:
				printf("\n %d是非法输入，按下回车后请务必重新输入！\n", selectNum);
		}
	}while(1);

	return;
}

