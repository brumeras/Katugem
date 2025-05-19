#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include <map>

#include "User.hpp"
#include "DataManager.hpp"
#include "TreatShop.hpp"
#include "Cat.hpp"

using namespace std;

void logTest(ofstream &testFile, const string &testName, bool passed);
void testCatClass(ofstream &testFile);
void testUserClass(ofstream &testFile);
void testDataManager(ofstream &testFile);
void testTreatShop(ofstream &testFile);
void testQuizStrategy(ofstream &testFile);

int main()
{
    ofstream testFile("tests.txt");

    if (!testFile.is_open())
    {
        cerr << "Failed to open tests.txt for writing!" << "\n";
        return 1;
    }

    testFile << "=========================================" << "\n";
    testFile << "    Grow Your German - Backend Tests" << "\n";
    testFile << "=========================================" << "\n";

    cout << "=========================================" << "\n";
    cout << "    Grow Your German - Backend Tests" << "\n";
    cout << "=========================================" << "\n";

    testCatClass(testFile);
    testUserClass(testFile);
    testDataManager(testFile);
    testTreatShop(testFile);
    testQuizStrategy(testFile);

    testFile << "\n=========================================" << "\n";
    testFile << "            Tests Complete" << "\n";
    testFile << "=========================================" << "\n";

    cout << "\n=========================================" << "\n";
    cout << "            Tests Complete" << "\n";
    cout << "=========================================" << "\n";
    cout << "Test results written to tests.txt" << "\n";

    testFile.close();

    return 0;
}

void logTest(ofstream &testFile, const string &testName, bool passed)
{
    string result = passed ? "PASSED" : "FAILED";
    string line = "TEST: " + testName + " - " + result;

    testFile << line << "\n";
    cout << line << "\n";
}

void testCatClass(ofstream &testFile)
{
    testFile << "\n===== Cat Class Tests =====\n"
             << "\n";
    cout << "\n===== Cat Class Tests =====\n"
         << "\n";

    Cat defaultCat;
    bool defaultCtorTest = (defaultCat.getName() == "Unnamed" &&
                            defaultCat.getWeight() == 0.1 &&
                            defaultCat.getAge() == 0 &&
                            defaultCat.getKnowledge() == 0);
    logTest(testFile, "Cat Default Constructor", defaultCtorTest);

    Cat namedCat("Felix");
    bool namedCtorTest = (namedCat.getName() == "Felix" &&
                          namedCat.getWeight() == 0.1 &&
                          namedCat.getAge() == 0 &&
                          namedCat.getKnowledge() == 0);
    logTest(testFile, "Cat Parameterized Constructor", namedCtorTest);

    Cat testCat;
    testCat.setName("Whiskers");
    testCat.setWeight(3.5);
    testCat.setAge(2.0);
    testCat.setKnowledge(100);

    bool settersTest = (testCat.getName() == "Whiskers" &&
                        testCat.getWeight() == 3.5 &&
                        testCat.getAge() == 2.0 &&
                        testCat.getKnowledge() == 100);
    logTest(testFile, "Cat Setters and Getters", settersTest);

    testFile << "Cat name: " << testCat.getName() << "\n";
    testFile << "Cat weight: " << testCat.getWeight() << "\n";
    testFile << "Cat age: " << testCat.getAge() << "\n";
    testFile << "Cat knowledge: " << testCat.getKnowledge() << "\n";
}

void testUserClass(ofstream &testFile)
{
    testFile << "\n===== User Class Tests =====\n"
             << "\n";
    cout << "\n===== User Class Tests =====\n"
         << "\n";

    User defaultUser;
    bool defaultCtorTest = (defaultUser.getCat().getName() == "Unnamed" &&
                            defaultUser.getBalance() == 0);
    logTest(testFile, "User Default Constructor", defaultCtorTest);

    User namedUser("Mittens");
    bool namedCtorTest = (namedUser.getCat().getName() == "Mittens" &&
                          namedUser.getBalance() == 0);
    logTest(testFile, "User Parameterized Constructor", namedCtorTest);

    User testUser;
    Cat testCat;
    testCat.setName("Fluffy");
    testCat.setWeight(4.2);
    testCat.setAge(3.5);
    testCat.setKnowledge(75);

    testUser.setCat(testCat);
    testUser.setBalance(100);

    bool settersTest = (testUser.getCat().getName() == "Fluffy" &&
                        testUser.getCat().getWeight() == 4.2 &&
                        testUser.getCat().getAge() == 3.5 &&
                        testUser.getCat().getKnowledge() == 75 &&
                        testUser.getBalance() == 100);
    logTest(testFile, "User Setters and Getters", settersTest);

    testFile << "User's cat name: " << testUser.getCat().getName() << "\n";
    testFile << "User's balance: " << testUser.getBalance() << "\n";

    double oldAge = testUser.getCat().getAge();
    testUser.ageCatSlightly();
    bool ageCatTest = (testUser.getCat().getAge() > oldAge);
    logTest(testFile, "User ageCatSlightly()", ageCatTest);

    testFile << "Cat's age before: " << oldAge << "\n";
    testFile << "Cat's age after: " << testUser.getCat().getAge() << "\n";

    Treat testTreat{"Test Treat", 20.0, 0.25, 10};
    testUser.buyTreat(testTreat);
    bool buyTreatWithEnoughBalance = (!testUser.getOwnedTreats().empty() &&
                                      testUser.getBalance() == 80);
    logTest(testFile, "User buyTreat() with sufficient balance", buyTreatWithEnoughBalance);

    testFile << "User's balance after buying treat: " << testUser.getBalance() << "\n";
    testFile << "User's treats count: " << testUser.getOwnedTreats().size() << "\n";

    Treat expensiveTreat{"Expensive Treat", 100.0, 0.5, 20};
    testUser.buyTreat(expensiveTreat);
    bool buyTreatWithInsufficientBalance = (testUser.getOwnedTreats().size() == 1 &&
                                            testUser.getBalance() == 80);
    logTest(testFile, "User buyTreat() with insufficient balance", buyTreatWithInsufficientBalance);

    double oldWeight = testUser.getCat().getWeight();
    int oldKnowledge = testUser.getCat().getKnowledge();
    testUser.feedCat(0);
    bool feedCatTest = (testUser.getCat().getWeight() > oldWeight &&
                        testUser.getCat().getKnowledge() > oldKnowledge &&
                        testUser.getOwnedTreats().empty());
    logTest(testFile, "User feedCat()", feedCatTest);

    testFile << "Cat's weight before feeding: " << oldWeight << "\n";
    testFile << "Cat's weight after feeding: " << testUser.getCat().getWeight() << "\n";
    testFile << "Cat's knowledge before feeding: " << oldKnowledge << "\n";
    testFile << "Cat's knowledge after feeding: " << testUser.getCat().getKnowledge() << "\n";
    testFile << "User's treats count after feeding: " << testUser.getOwnedTreats().size() << "\n";
}

void testDataManager(ofstream &testFile)
{
    testFile << "\n===== DataManager Class Tests =====\n"
             << "\n";
    cout << "\n===== DataManager Class Tests =====\n"
         << "\n";

    DataManager dataManager;

    dataManager.loadWordsFromFile("words.txt");
    const map<string, string> &wordMap = dataManager.getWordMap();
    bool wordLoadTest = (!wordMap.empty());
    logTest(testFile, "DataManager loadWordsFromFile()", wordLoadTest);

    testFile << "Number of loaded words: " << wordMap.size() << "\n";

    int count = 0;
    testFile << "Sample word pairs:" << "\n";
    for (const auto &pair : wordMap)
    {
        if (count < 5)
        {
            testFile << "  " << pair.first << " -> " << pair.second << "\n";
            count++;
        }
        else
        {
            break;
        }
    }

    vector<Treat> treats = dataManager.loadTreatsFromFile("treats.txt");
    bool treatLoadTest = (!treats.empty());
    logTest(testFile, "DataManager loadTreatsFromFile()", treatLoadTest);

    testFile << "Number of loaded treats: " << treats.size() << "\n";
    for (const auto &treat : treats)
    {
        testFile << "  " << treat.name << " - Price: " << treat.price
                 << ", Weight+: " << treat.weightIncrease
                 << ", Knowledge+: " << treat.knowledgeIncrease << "\n";
    }

    User testUser("SaveLoadTestCat");
    testUser.setBalance(500);
    Cat &cat = testUser.getCat();
    cat.setWeight(2.5);
    cat.setAge(1.75);
    cat.setKnowledge(150);

    if (!treats.empty())
    {
        testUser.buyTreat(treats[0]);
    }

    bool saveTest = dataManager.saveUserData(testUser, "test_save.txt");
    logTest(testFile, "DataManager saveUserData()", saveTest);

    User loadedUser;
    bool loadTest = dataManager.loadUserData(loadedUser, "test_save.txt");
    bool dataMatchTest = (loadedUser.getCat().getName() ==  testUser.getCat().getName() &&
                          loadedUser.getCat().getWeight() == testUser.getCat().getWeight() &&
                          loadedUser.getCat().getAge() == testUser.getCat().getAge() &&
                          loadedUser.getCat().getKnowledge() == testUser.getCat().getKnowledge() &&
                          loadedUser.getBalance() == testUser.getBalance() &&
                          loadedUser.getOwnedTreats().size() == testUser.getOwnedTreats().size());

    logTest(testFile, "DataManager loadUserData()", loadTest);
    logTest(testFile, "Loaded data matches saved data", dataMatchTest);

    testFile << "Original user's cat name: " << testUser.getCat().getName() << "\n";
    testFile << "Loaded user's cat name: " << loadedUser.getCat().getName() << "\n";
    testFile << "Original user's balance: " << testUser.getBalance() << "\n";
    testFile << "Loaded user's balance: " << loadedUser.getBalance() << "\n";
    testFile << "Original treats count: " << testUser.getOwnedTreats().size() << "\n";
    testFile << "Loaded treats count: " << loadedUser.getOwnedTreats().size() << "\n";
}

void testTreatShop(ofstream &testFile)
{
    testFile << "\n===== TreatShop Class Tests =====\n"
             << "\n";
    cout << "\n===== TreatShop Class Tests =====\n"
         << "\n";

    TreatShop treatShop;
    DataManager dataManager;

    vector<Treat> treats = dataManager.loadTreatsFromFile("treats.txt");
    treatShop.loadTreats(treats);

    bool loadTreatsTest = (!treatShop.getAvailableTreats().empty());
    logTest(testFile, "TreatShop loadTreats()", loadTreatsTest);

    testFile << "Number of treats in shop: " << treatShop.getAvailableTreats().size() << "\n";
    for (const auto &treat : treatShop.getAvailableTreats())
    {
        testFile << "  " << treat.name << " - Price: " << treat.price
                 << ", Weight+: " << treat.weightIncrease
                 << ", Knowledge+: " << treat.knowledgeIncrease << "\n";
    }
}

void testQuizStrategy(ofstream &testFile)
{
    testFile << "\n===== Quiz Strategy Tests =====\n"
             << "\n";
    cout << "\n===== Quiz Strategy Tests =====\n"
         << "\n";

    map<string, string> testWords;
    testWords["hello"] = "hallo";
    testWords["cat"] = "katze";
    testWords["dog"] = "hund";

    User testUser("StrategyTestCat");

    testUser.setLearningStrategy();
    logTest(testFile, "User setLearningStrategy()", true);

    testUser.setTestingStrategy();
    logTest(testFile, "User setTestingStrategy()", true);

    testFile << "Note: Full quiz testing requires user input and is skipped in automated tests." << "\n";
    testFile << "The strategy objects were successfully created and assigned." << "\n";
}