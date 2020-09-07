#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>

class Property {

private:
	// Property ID
	int m_propertyID;

	// Group ID the property belongs too
	int m_propertyGroupID;

	// Number of houses on property
	int m_numHouses;

	// Number of hotels on property
	int m_numHotels;

	// Price  of property
	int m_price;

	// Rent if no houses on property
	int m_rent;

	// Rent if no houses on property
	int m_monopolyRent;

	// Rent if one house on property
	int m_oneHouseRent;

	// Rent if two houses on property
	int m_twoHouseRent;

	// Rent if three houses on property
	int m_threeHouseRent;

	// Rent if four houses on property
	int m_fourHouseRent;

	// Rent if hotel on property
	int m_hotelRent;

	// If this is a property that has a mandatory fee for landing on it
	int m_fee;

	// If this is a property where you get a reward for landing on it
	int m_reward;

	// Value if owner decides to sell it
	int m_mortgageValue;

	// Cost to put house on property
	int m_buildingCost;

	// Property owner's ID
	int m_propertyOwnerID;

	// Property is owned by someone
	bool m_isOwned;

	// Name of property
	std::string m_name;

public:
	Property();

	int getNumHouses();
	void setNumHouses(int numHouses);

	int getNumHotels();
	void setNumHotels(int numHotels);

	int getPrice();
	void setPrice(int price);

	std::string getName();
	void setName(std::string name);

	int getRent();
	void setRent(int rent);

	int getMonopolyRent();
	void setMonopolyRent(int monopolyRent);

	int getOneHouseRent();
	void setOneHouseRent(int rent);

	int getTwoHouseRent();
	void setTwoHouseRent(int rent);

	int getThreeHouseRent();
	void setThreeHouseRent(int rent);

	int getFourHouseRent();
	void setFourHouseRent(int rent);

	int getHotelRent();
	void setHotelRent(int rent);

	int getFee();
	void setFee(int fee);

	int getReward();
	void setReward(int reward);

	bool getIsOwned();
	void setIsOwned(bool isOwned);

	int getMortgageValue();
	void setMortgageValue(int mortgageValue);

	int getBuildingCost();
	void setBuildingCost(int buildingCost);

	int getHotelCost();
	void setHotelCost(int hotelCost);

	int getPropertyID();
	void setPropertyID(int id);

	int getPropertyGroupID();
	void setPropertyGroupID(int id);

	int getPropertyOwnerID();
	void setPropertyOwnerID(int id);

};

#endif