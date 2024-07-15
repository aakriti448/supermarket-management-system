/*                    GROUP PROJECT
limitation: NO ERROR HANDLING SO if qunatity and price is not entered as in provides
               it doesnt give any error
2.bill doesnt display name of item bought by customer.it only shows total cost
3.NO UPDATE and delete system code*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class item{
	private:
		char name[100], uic[50];
		float price[100000];
		int quant[100];
	public:

		int i,n;
        void createBill(item*pobj , item*fobj )/////////////////////////////function2
		 {
               ofstream billFile("bill.txt");

    if (billFile.is_open())
	{
        float totalCost = pobj->calculateTotal() + fobj->calculateTotal();

        billFile << "Total Cost for Packed Groceries: " << pobj->calculateTotal() << std::endl;

        billFile << "Total Cost for Fresh Groceries: " << fobj->calculateTotal() << std::endl;

        billFile << "\nTotal Cost for all Groceries: " << totalCost << std::endl;

        std::cout << "Bill created and stored in 'bill.txt'." << std::endl;

        billFile.close();

    }
		 }

		 void showpackedG()/////////////////////////////////////////////////function 3
		 {
            ifstream in;
			string st;
			in.open("packedG.txt");
			while(in.eof()==0)
			{
				getline(in,st);
				cout<<st<<endl;
			}
		 }
		 void showfreshG() /////////////////////////////////////////////////////func4
		 {
            ifstream in;
			string st2;
			in.open("freshG.txt");
			while(in.eof()==0)
			{
				getline(in,st2);
				cout<<st2<<endl;
			}
		 }

		  void getdata()
    {
        int i,n;
		float totalquat;
		cout<<"Enter number of products you want to buy?"<<endl;
		cin>>n;
		for(i=0;i<=n;i++)
		{
	    cout<<"Product[i]"<<endl;
        cout<<"Enter name of product you want to buy"<<endl;
        cin>>name;
        cout<<"Enter quantity of product(must not be more than available on lsit)"<<endl;
        cin>>quant[i];
        cout<<"Enter price of product"<<endl;
        cin>>price[i];
        cout<<"Enter uic of product"<<endl;
        cin>>uic;
		}
    
    }
	float calculateTotal()
		{
          for(i=0;i<=n;i++)
		{
			float totalcost;
			totalcost=price[i]*quant[i];	
		}
		}

		 
    };
    
class packedG :public item 
{
    public:
    void getDetails() 
	{
     int count1=0;
     char arr1[100];
     cout<<"Enter the no of products you want to add/append ";
 	 cin>>count1;
    
     fstream myfile("packedG.txt", ios::out | ios::app);
    	cin.ignore();

     if (myfile.is_open()) 
	 {
    	while(count1!=0)
		{
    		
    	cout << "\nEnter the Name of a new product: ";
        cin.getline(arr1, 100);
        // myfile << "Name: " << arr1 << endl;
		myfile << setw(14)<< arr1;

        cout << "Enter the UIC of a new product: ";
        cin.getline(arr1, 100);
        // myfile << "UIC: " << arr1 << endl;
		myfile <<setw(6) << arr1;


        cout << "Enter the Price of new product: ";
        cin.getline(arr1, 100);
        // myfile << "Price: " << arr1<< endl;
		myfile <<setw(8) << arr1;

        cout << "Enter the quantity of a new product: ";
        cin.getline(arr1, 100);
        // myfile << "Quantity: " << arr1 << endl;
		myfile << setw(9) << arr1<< endl;
        count1--;

       
        cin.ignore(); 
        
      }
	};

     cout << "Data recorded successful" << endl;
};

class freshG :public item 
{
    public:
    void getDetails() 
	{

     int count2=0;
     char arr2[100];
     cout<<"Enter the no of products you want to add to cart: ";
 	 cin>>count2;
    
     fstream myfile("freshG.txt", ios::out | ios::app);
    	cin.ignore();

     if (myfile.is_open()) 
	 {
    	while(count2!=0)
		{
    		
    	cout << "\nEnter the Name of a new product: ";
        cin.getline(arr2, 100);
        // myfile << "Name: " << arr2 << endl;
	    myfile << setw(14)<< arr2;



        cout << "Enter the UIC of a new product: ";
        cin.getline(arr2, 100);
        // myfile << "UIC: " << arr2;
		 myfile <<setw(6) << arr2;

        cout << "Enter the Price of new product: ";
        cin.getline(arr2, 100);
        // myfile << "Price: " << arr2<< endl;
		myfile <<setw(8) << arr2;

        cout << "Enter the quantity of a new product: ";
        cin.getline(arr2, 100);
        myfile << setw(9) << arr2<< endl;

        cin.ignore(); 
        count2--;
       }
	}
	}
};

int main()

{
	
	item obj[20];
	packedG pobj;
	freshG fobj;
	int i=0,choice1,choice2,count1,count2;


	while(1)
	{
		cout<<"--------------------------------------------"<<endl;
		cout<<"Main Menu:"<<endl;
		cout<<"1. List all products"<<endl;
		cout<<"2. Add Packed Groceries"<<endl;
		cout<<"3. Add Fresh Groceries"<<endl;
		cout<<"4. Purchase"<<endl;
		cout<<"Your Choice: ";
		cin>>choice1;
		
		switch(choice1)
		{
			
			case 1:
			{
				cout<<"--------------------------------------------"<<endl;
				// cout<<"\tList of all products:\t\t\t\t"<<endl;
				// cout<<"Name \t\t\t\tUIC\t\t\tPrice "<<endl;
				// cout<<"List of PACKED GROCERIES "<<endl;
				// cout<<"juice\t\t\t\tj\t\t\t50 "<<endl;
				// cout<<"chocolate \t\t\tc\t\t\t45 "<<endl;
				showpackedG();//................create file before executiing.....................

				cout<<"--------------------------------------------"<<endl;
				// cout<<"List of FRESH GROCERIES "<<endl;
				// cout<<"Name \t\t\t\tUIC\t\t\tPrice "<<endl;
				// cout<<"apple \t\t\t\ta\t\t\t20"<<endl;
				// cout<<"banana \t\t\t\tb\t\t\t30 "<<endl;
				// cout<<"--------------------------------------------"<<endl;
				showfreshG();
			break;
			}
			
			case 2:
                pobj.getDetails();
			break;
			
			case 3:
				fobj.getDetails();
			break;
			
			case 4:
			{
			m:
				cout<<"Second Main Menu"<<endl;
				cout<<"1. Go to Packed Groceries"<<endl;
				cout<<"2. Go to Fresh Groceries"<<endl;
				cout<<"3. BILL"<<endl;
				cout<<"0. Go Back"<<endl;
				cout<<"Your Choice: ";
				//obj[i].getdata();//
				cin>>choice2;
				
				switch(choice2)
				{
				
					case 1:
					{
                       
                     showpackedG();
					 pobj.getdata();
					break;
					}
					
					case 2:
					{
						showfreshG();
						fobj.getdata();
						break;

					}

					case 3:
						obj[i].	createBill(&pobj,&fobj);
					break;
					
					case 0:
					break;
					
					default:
				         cout<<"Option Invalid!!!!!"<<endl;
				    break;
				
				}

				goto m;
			}				

		}
	}
	
}