#pragma once

class BankAccount
{
private:
	char name[51];
	char bankAccountNumber[23];
	float availabilityCash;

public:
	BankAccount();
	BankAccount(const char* _name, const char* IBAN, const float& cash);

	const void getInfo();
	void Deposit(const float& input);
	void Widthdraw(const float& input);

	const char* getName() const;
	void setName(const char* _name);

	const char* getBankAccountNumber() const;
	void setBankAccountNumber(const char* _BAN);

	const float& getAvailabilityCash() const;
	void setAvailabilityCash(const float& _cash);
};