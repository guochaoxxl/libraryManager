#include "book.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct _book{
	int bookNum;												//图书编号
	char bookName[NameSize];									//图书名称
	char bookISBN[ISBNSize];									//图书ISBN
	char bookAuthor[AuthorSize];								//图书作者
	char bookPress[PressSize];									//图书出版社
	float bookPrice;											//图书价格
	int bookStock;												//图书存量
} Book;*/

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
void readBookInfo(FILE *fp, Book *ptrBook){
	fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);

	return;
}

//写入文件
void writeBookInfo(FILE *fp, Book *ptrBook){
	fprintf(fp, "\n%d\t%s\t%s\t%s\t%s\t%f\t%d", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);

	return;
}

//显示文件
void diskBookInfo(Book *ptrBook){
	printf("图书信息：编号：%d\t 名称：%s\t ISBN：%s\t 作者：%s\t 出版社：%s\t 价格：%f\t 存量：%d\n", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);

	return;
}

//信息输入
Book* inBookInfo(){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
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

	return ptrBook;
} 

//信息固化
void inBookInfoFile(FILE *fp, Book *ptrBook){
	fprintf(fp, "\n%d\t%s\t%s\t%s\t%s\t%f\t%d", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);
	printf("\n刚刚添加了%s图书，按任意键继续……", ptrBook->bookName);
	getchar();
	getchar();
	fclose(fp);

	return;
}

//显示所有图书信息
void outBookInfo(FILE *fp){
	fp = fopen("fileBook.txt", "r");
	printf("添加图书后所有图书如下： ");
	while(!feof(fp)){
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		printf("图书信息：编号：%d\t 名称：%s\t ISBN：%s\t 作者：%s\t 出版社：%s\t 价格：%f\t 存量：%d\n", ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, ptrBook->bookPrice, ptrBook->bookStock);
		printf("按任意键继续……");
		getchar();
		getchar();
		fclose(fp);
	}

	return;
}

//图书查找-按编号
Book *findBookByNum(int bookNum, FILE *fp){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(ptrBook->bookNum == bookNum){
			return ptrBook;
		}
	}

	return NULL;
}

//图书查找-按作者
Book *findBookByAuthor(int bookAuthor, FILE *fp){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(strcmp(ptrBook->bookAuthor == bookAuthor) == 0){
			return ptrBook;
		}
	}

	return NULL;
}

//图书查找-按ISBN
Book *findBookByISBN(int bookISBN, FILE *fp){
	Book *ptrBook = (Book *)malloc(sizeof(Book));
	while(!feof(fp)){
		fscanf(fp, "%d%s%s%s%s%f%d", &ptrBook->bookNum, ptrBook->bookName, ptrBook->bookISBN, ptrBook->bookAuthor, ptrBook->bookPress, &ptrBook->bookPrice, &ptrBook->bookStock);
		if(strcmp(ptrBook->bookISBN == bookISBN) == 0){
			return ptrBook;
		}
	}

	return NULL;
}

//添加图书
void addBook(){
	//创建图书文件
	FILE *fp = fopenC("bookFile.txt");
	//添加图书信息
	Book *bookPtr = inBookInfo();
	//将图书信息写入文件
	inBookInfoFile(fp, bookPtr);
	//显示添加后的所有图书文件
	outBookInfo(fp);

	return;
}

//删除图书
void deleBookByNum(){
	//打开图书文件读
	FILE *fpR = fopenR("bookFile.txt");
	//打开图书文件写
	FILE *fpW = fopenW("bookFiletmp.txt");
	int flag = 1;
	int bookNum;
	printf("请输入要删除的图书的编号：");
	scanf("%d", &bookNum);
	while(!feof(fpR)){
		Book *ptrBook = (Book *)malloc(sizeof(Book));
		readBookInfo(fpR, ptrBook);
		if(findBookByNum(bookNum, fpR) != NULL){
			flag = 0;
			continue;
		}

		writeBookInfo(fpW, ptrBook);
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


	return;
}

//编辑图书
void editBook(){
	
}

//查找图书
void findBook(){

}

//图书菜单
void menuBook(){

}
