#include "user.h"
#include"product.h"
#include<iostream>
#include<vector>
#pragma once


class seller : public user
{

public:
	
	seller(string name, string email, string password);
	string test = "Hello " + name;
	product pro;
	product proloop;
	product_type sel;
	product_type addingProduct();
	void deletProduct();
	void UpdateProduct(int idToBeUpdated);
	

};
