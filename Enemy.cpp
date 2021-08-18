#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

using namespace std;

void Enemy::SetIsBoss(bool isBoss){
	this->theBoss = isBoss;
}

void Enemy::SetNeedBacon(bool theBacon){
	this->theBacon = theBacon;
}

void Enemy::SetRequiredItems(vector <Item> baconList) {
	this->reqItems = baconList;
}

void Enemy::AddToReqItems(Item item) {
	this->reqItems.push_back(item);
}

void Enemy::SetHp(double hp) {
	this->health = hp;
}

void Enemy::SetShield(double shield) {
	this->shield = shield;
}

void Enemy::SetDmg(double dmg) {
	this->dmg = dmg;
}

void Enemy::SetName(string name) {
	this->enemyName = name;
}

bool Enemy::GetIsBoss() {
	return this->theBoss;
}

bool Enemy::GetTheBacon() {
	return this->theBacon;
}

vector <Item> Enemy::GetRequiredItems() {
	return reqItems;
}

double Enemy::GetHp() {
	return this->health;
}

double Enemy::GetShield() {
	return this->shield;
}

string Enemy::GetName() {
	return this->enemyName;
}

double Enemy::GetDmg() {
	return this->dmg;
}

void Enemy::SetID(double ID) {
	this->enemyID = ID;
}

double Enemy::GetEnemyID() {
	return enemyID;
}