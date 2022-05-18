#include "Customer.h"
#include<iostream>
using namespace std;
Customer::Customer(string name, string email, string password, string address, string phone)
	:user(name, email, password)
{
	this->address = address;
	this->phone = phone;
}
Customer::Customer(string name, string email, string password)
	: user(name, email, password)
{
	
}
deque<product_type> Customer::browseByCategory() {
	cout << "Enter Product Category :" << endl;
	string searchCat;
	cin >> searchCat;
	deque<product_type> q = myProduct.searchByCategory(searchCat);

	return q;

}
deque<product_type> Customer::browseByName() {
	cout << "Enter Product Name :" << endl;
	string searchName;
	cin >> searchName;
	deque<product_type> q = myProduct.searchByName(searchName);
	



	return q;
}

void Customer::addProductToCart(product_type p, int q)
{
	cart_type temp;
	
	if (p.quantity < q) {
		cout << "Sorry, no sufficient quantiy" << endl;
		cout << "Available " << p.quantity << " from this product now" << endl;
	}
	else {
		temp.cart_products = p;
		temp.ordered_quantity = q;
		mycart.addToCart(temp);
		cout << "Product Added To Cart" << endl;
	}
}

void Customer::viewCart()
{
	for (int i = 0; i < mycart.prod.size(); i++) {
		cout << "Item " << i + 1 << " " << mycart.prod[i].cart_products.name << endl;
	}
	if (!mycart.prod.empty()) {
		int c;
		cout << "Enter 1 to confirm order all products\nEnter 2 to remove product from cart" << endl;
		cin >> c;

		if (c == 1) {
			confirmOrder();
		}
		else if (c == 2) {
			
			cout << "Enter product id to remove from cart" << endl;
			
			int rem_id;
			cin >> rem_id;
			bool isRemoved = mycart.removeFromCart(rem_id);
			if (isRemoved) {
				cout << "Product Removed Successfully" << endl;
			}
			else {
				cout << "Product is not in the cart" << endl;
			}
		}
		else {
			return;
		}
	}
	
	mycart.displayTotalPrice();
}

void Customer::confirmOrder() {
	order newOrder = order(this->name, this->address, this->phone, this->mycart.prod);

}


void Customer::Order_Screen() {
	int ch;

	do {
		cout << endl;
		cout << "1 - Search for a product by name.\n";
		cout << "2 - Search for a product by category.\n";
		cout << "3 - View or Confirm Cart.\n";
		cout << "4 - Sign Out.\n";
		cout << endl;

		int choice;
		cin >> choice;
		if (choice == 1) {
			deque<product_type> searchProducts = browseByName();
			do {
				cout << "Enter product id to Add this product to cart\nEnter 0 to cancel search" << endl;
				cin >> ch;
				int quantity;
				
				for (int i = 0; i < searchProducts.size(); i++) {
					if (searchProducts[i].id == ch) {
						cout << "Please Enter Quantity" << endl;
						cin >> quantity;
						addProductToCart(searchProducts[i], quantity);
						
					}
				}
			} while (ch != 0);

		}
		else if (choice == 2) {
			deque<product_type> searchProducts = browseByCategory();
			do {
				cout << "Enter product id to Add this product to cart\nEnter 0 to cancel search" << endl;
				cin >> ch;
				int quantity;

				for (int i = 0; i < searchProducts.size(); i++) {
					if (searchProducts[i].id == ch) {
						cout << "Please Enter Quantity" << endl;
						cin >> quantity;
						addProductToCart(searchProducts[i], quantity);

					}
				}
			} while (ch != 0);
		}
		else if (choice == 3) {
			viewCart();
		}
		else if (choice == 4) {
			break;
		}
		cout << "Enter 0 to back to menu\n";
		cin >> ch;
	} while (ch == 0);
}