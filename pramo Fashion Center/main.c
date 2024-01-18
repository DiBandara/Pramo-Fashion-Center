#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<ctype.h>
/* customer */
char CustomerName[30];
int Item_code[500] ;
int Number_of_Item[500] ;
float Total[500];
int t ;
int i ;

/* Administrator */

struct Item {

    int ProductCode;
    char ProductName[20];
    int Quantity;
    float Price;
}
Item ;

int main(){

    int Option;

    system("cls");
    printf("\t\t*************** Pramo Fashion Center ***************\n\n");
    printf("\t\t1. Details\n");
    printf("\t\t2. Cashier\n");
    printf("\t\t3. Exit\n\n");
    printf("\t\tPlease Select a Option : ");
    scanf("%d",&Option);

    for(;;){
        if (Option == 1 ){
            Details();
            break;
        }

        else if (Option == 2 ){
            Calculate_Bill();
            break;
        }
        else if (Option == 3 ){

           system("Exit");
           break;
        }

        else {
            printf("\tPlease Select Correct Number : ");
            scanf("%d", &Option);
        }
    }

    return 0;
}


int Details(){

    int adOption ;

    system("cls");

    printf("\t\t*************** Pramo Fashion Center ***************\n\n");

    printf("\t1. Create/Add Product List\n");
    printf("\t2. Delete All Product List\n");
    printf("\t3. Product List\n");
    printf("\t4. Search Products\n");
    printf("\t5. Delete Product\n");
    printf("\t6. Exit Main Menu\n\n");

    printf("\tPlease Select a Number : ");
    scanf("%d", & adOption);

    for(;;){
        if ( adOption == 1 ){
            Create_Product_List();
            break;
        }
        else if ( adOption == 2 ) {
            Delete_All_Product_List();
            break;
        }
        else if ( adOption == 3 ) {
            Product_List();
            break;
        }
        else if ( adOption == 4 ) {
            SearchProduct();
            break;
        }
        else if ( adOption == 5 ) {
            DeleteProduct();
            break;
        }
        else if ( adOption == 6 ) {
            main();
            break;
        }


        else {
            printf("Please Select Correct Number : ");
            scanf("%d", &adOption);
        }
    }

    return 0 ;
}


int Create_Product_List(){

    int Exit;

    FILE *ProductList;
    struct Item info;


    for(;;){

        system("cls");
        printf("\t\t*************** Pramo Fashion Center ***************\n\n");

        ProductList = fopen("ProductList.txt", "a");

        printf("Enter The Product Code     : ");
        scanf("%d", &info.ProductCode);

        printf("Enter The Product Name     : ");
        scanf("%s", &info.ProductName);

        printf("Enter The Product Quantity : ");
        scanf("%d", &info.Quantity);

        printf("Enter The Product Price    : ");
        scanf("%f", &info.Price);

        fwrite(&info,sizeof(struct Item), 1 , ProductList);
        fclose(ProductList);

        printf("\nAdd More Item [ Yes - 1 / No - 0 ] : ");
        scanf("%d", &Exit);

        if ( Exit == 0 ) {  Details();}
        else { continue;}
    }
    return 0;
}

int Delete_All_Product_List(){

    remove("ProductList.txt");

    system("pause");
    Details();
}

int Product_List(){

    int x=1;


    system("cls");

    FILE *productList;
    struct Item info;

    printf("\t\t*************** Pramo Fashion Center ***************\n\n");

    printf("\t\t\t============ Product List ============\n\n");

    productList = fopen("ProductList.txt", "r");

    printf("\tNO\tCode\t\tName\t\t\t\tQuantity\t\tPrice\n\n");

    while (fread(&info,sizeof(struct Item), 1, productList )){

        printf("\t%d\t", x);
        printf("%d\t\t", info.ProductCode);
        printf("%s\t\t\t\t", info.ProductName);
        printf("%d\t\t\t", info.Quantity);
        printf("%f\n", info.Price);
        x++;
    }

    printf("\n\n\n");
    system("pause");

    Details();

    return 0;
}

int DeleteProduct(){

    int Delet_Product_Code;


    struct Item info;

    FILE *productList, *temp;
    productList = fopen("ProductList.txt", "r");
    temp = fopen("temp.txt", "a+");

    system("cls");

    printf("\tEnter The Product Code : ");
    scanf("%d", &Delet_Product_Code);

    while (fread(&info,sizeof(struct Item), 1, productList )) {

        if ( info.ProductCode != Delet_Product_Code ) {

            fwrite(&info,sizeof(struct Item), 1 , temp);
        }
    }
    fclose(productList);
    fclose(temp);

    remove("ProductList.txt");
    rename("temp.txt","ProductList.txt" );

    printf("\n\n");
    printf("\tProduct Delete Successfull........\n\n");

    system("pause");
    Details();

return 0;
}



int SearchProduct(){

    int Search;

    struct Item info;

    FILE *productList;
    productList = fopen("ProductList.txt", "r");

    printf("\tEnter The Product Code : ");
    scanf("%d", &Search);
    system("cls");

    printf("\t\t*************** Pramo Fashion Center ***************\n\n");

    printf("\tCode\t\tName\t\t\t\tQuantity\t\tPrice\n\n");

    while (fread(&info,sizeof(struct Item), 1, productList )){

        if ( info.ProductCode == Search ){

            printf("\t%d\t\t", info.ProductCode);
            printf("%s\t\t\t\t", info.ProductName);
            printf("%d\t\t\t", info.Quantity);
            printf("%f\n", info.Price);
        }

    }
    printf("\n\n");
    system("pause");
    Details();

    return 0;
}

int Calculate_Bill(){

    float Price;

    system("cls");
    printf("\t\t*************** Pramo Fashion Center ***************\n\n");

    struct Item info;

    for(;;) {

       printf("\tExit to Main Menu [Yes- -123] \n ");

        for (i=0; i<=500; i++){

            if (i>0) { printf("\t\t*************** Pramo Fashion Center ***************\n\n");}

            printf("\tGet Bill to Enter Item code in [Yes- 0 ]\n\n");

            printf("\tEnter Item Code :- ");
            scanf("\n%d",&Item_code[i]);

            if ( Item_code[i] == -123) { main(); }

            else if ( Item_code[i] == 0 ) {
                printf("\tEnter Customer Name :- ");
                scanf("\n%s",&CustomerName);

                Bill();
            }

            else {
                printf("\tEnter Number Of Item :- ");
                scanf("\n%d",&Number_of_Item[i]);

                FILE *productList;
                productList = fopen("ProductList.txt", "r");

                 while (fread(&info,sizeof(struct Item), 1, productList )){

                    if ( Item_code[i] == info.ProductCode ){
                        Price = info.Price;
                    }
                 }

                 Total[i] = Number_of_Item[i]*Price;
            }

            system("cls");
        }
    }
    return 0;
}

void Bill(){

    int Open;
    int k ;
    int l;
    float SubTotal = 0 ;
    float Discount = 0 ;
    float NetTotal = 0 ;
    float Cash     = 0 ;
    float Balance  = 0 ;
    time_t t;
    float sum=0;

    for(k=0; k<=i-1; k++){

       SubTotal = SubTotal + Total[k];
    }


    if ( SubTotal >= 2000 ) {

        Discount = (SubTotal*5)/100;
    }
    else if ( SubTotal >=6000 ){

        Discount = ( SubTotal*8)/100;
    }
    else if ( SubTotal >= 12000 ) {

        Discount = ( SubTotal*10 )/100;
    }

    else if ( SubTotal >= 20000 ) {

        Discount = ( SubTotal*15 )/100;
    }
    else if ( SubTotal < 2000) {

        Discount = 0 ;
    }

    NetTotal = SubTotal - Discount;

    t= time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);


    system("cls");

    printf("\t\t*************** Pramo Fashion Center ***************\n");
    printf("\t\t\t      No.22/A Matara Road Galle\n\t\t\t\t  TEL :- 071-2839087\n\n");
    printf("\tDate & Time : %d-%d-%d\t", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("%d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec );
    printf("\tInvoice To :  %s\n", &CustomerName);

    printf("\t===============================================================\n");
    printf("\t\tItem Name\t\tQty\t\tTotal\n");

    printf("\t===============================================================\n");
    for(k=0; k<=i-1; k++) {

        printf("\t\t%d\t\t\t%d\t\t%f\n", Item_code[k], Number_of_Item[k], Total[k]);

    }
    printf("\t===============================================================\n");

    printf("\tSub Total      :\t\t\t\t%f\n", SubTotal);
    printf("\tDiscount       :\t\t\t\t%f\n", Discount);
    printf("\tNet Total      :\t\t\t\t%f\n", NetTotal);

    printf("\t===============================================================\n");
    printf("\tCash           :\t\t\t\t");
    scanf("%f", &Cash);

    Balance = Cash - NetTotal;
    printf("\tBalance        :\t\t\t\t%f\n\n", Balance);

    printf("\t===============================================================\n");

    printf("\tNO Of Items    : %d\n", k);
    printf("\tDiscount       : %f\n\n", Discount );

    printf("\t\t\t......THANK YOu......\n");
    printf("\t\t\t   Have A Nice Day\n\n\n");


    system("pause");

    return 0 ;
}















