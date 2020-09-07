#include "stdafx.h"
#include <string>
#include "Property.h"

Property::Property() {
	int i = 0;
}

/**Property::~Property(){

}*/

int Property::getNumHouses(){
	return m_numHouses;
}

void Property::setNumHouses(int numHouses){
	m_numHouses = numHouses;
}

int Property::getNumHotels(){
	return m_numHotels;
}
void Property::setNumHotels(int numHotels){
	m_numHotels = numHotels;
}

int Property::getPrice(){
	return m_price;
}
void Property::setPrice(int price){
	m_price = price;
}

std::string Property::getName(){
	return m_name;
}
void Property::setName(std::string name){
	m_name = name;
}

int Property::getRent(){
	return m_rent;
}
void Property::setRent(int rent){
	m_rent = rent;
}

int Property::getMonopolyRent(){
	return m_monopolyRent;
}
void Property::setMonopolyRent(int monopolyRent){
	m_monopolyRent = monopolyRent;
}
int Property::getOneHouseRent(){
	return m_oneHouseRent;
}
void Property::setOneHouseRent(int oneHouseRent){
	m_oneHouseRent = oneHouseRent;
}

int Property::getTwoHouseRent(){
	return  m_twoHouseRent;
}
void Property::setTwoHouseRent(int twoHouseRent){
	m_twoHouseRent = twoHouseRent;
}

int Property::getThreeHouseRent(){
	return m_threeHouseRent;
}
void Property::setThreeHouseRent(int threeHouseRent){
	m_threeHouseRent = threeHouseRent;
}

int Property::getFourHouseRent(){
	return m_fourHouseRent;
}
void Property::setFourHouseRent(int fourHouseRent){
	m_fourHouseRent = fourHouseRent;
}

int Property::getHotelRent(){
	return m_hotelRent;
}
void Property::setHotelRent(int hotelRent){
	m_hotelRent = hotelRent;
}

int Property::getFee(){
	return m_fee;
}
void Property::setFee(int fee){
	m_fee = fee;
}

int Property::getReward(){
	return m_reward;
}
void Property::setReward(int reward){
	m_reward = reward;
}

bool Property::getIsOwned(){
	return m_isOwned;
}

void Property::setIsOwned(bool isOwned){
	m_isOwned = isOwned;
}

int Property::getMortgageValue(){
	return m_mortgageValue;
}
void Property::setMortgageValue(int mortgageValue){
	m_mortgageValue = mortgageValue;
}

int Property::getBuildingCost(){
	return m_buildingCost;
}
void Property::setBuildingCost(int buildingCost){
	m_buildingCost = buildingCost;
}

int Property::getPropertyID(){
	return m_propertyID;
}
void Property::setPropertyID(int propertyID){
	m_propertyID = propertyID;
}

int Property::getPropertyOwnerID(){
	return m_propertyOwnerID;
}
void Property::setPropertyOwnerID(int propertyOwnerID){
	m_propertyOwnerID = propertyOwnerID;
}

int Property::getPropertyGroupID(){
	return m_propertyGroupID;
}
void Property::setPropertyGroupID(int propertyGroupID){
	m_propertyGroupID = propertyGroupID;
}


