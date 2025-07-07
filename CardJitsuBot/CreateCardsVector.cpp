#include "CreateCardsVector.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

vector<Card> CreateCardsVector() {
	vector<Card> cards;
	cout << "Starting loop to read images..." << endl;
	for (const auto& image : fs::directory_iterator("images")) {
		if (fs::is_regular_file(image)) {
			string src = image.path().string();
			Card card(src);
			card.SetCardName();
			card.SetCardValue();
			cards.push_back(card);
			cout << "Card added: " << card.GetCardName() << endl;
		}
	}
	return cards;
}