#include <bits/stdc++.h>
using namespace std;
struct UmaMusume
{
    array<int, 6> grow;
    array<int, 6> stats;

    void init()
    {
        for (int i = 0; i < 5; ++i)
            stats[i] = min(1200, stats[i]);
        grow[5] = 0;
        stats[5] = 120;
    }
};

struct SupportCard
{
    int friend_, drive_, train_;
    array<int, 6> stats;
    array<int, 6> statsPlus;
};

struct Training
{
    int summer, weight, drive, type;
    vector<pair<int, int>> Cards;
};

struct TrainingSimulator
{
    UmaMusume uma;
    vector<SupportCard> Cards;
    vector<Training> trainings;

    const int baseTrainingValues[5][6][6] = {
        {{10, 0, 5, 0, 0, 2}, {11, 0, 5, 0, 0, 2}, {12, 0, 5, 0, 0, 2}, {13, 0, 5, 0, 0, 2}, {14, 0, 5, 0, 0, 2}},
        {{0, 9, 0, 4, 0, 2}, {0, 10, 0, 4, 0, 2}, {0, 11, 0, 4, 0, 2}, {0, 12, 0, 4, 0, 2}, {0, 13, 0, 4, 0, 2}},
        {{0, 5, 8, 0, 0, 2}, {0, 5, 9, 0, 0, 2}, {0, 6, 10, 0, 0, 2}, {0, 6, 11, 0, 0, 2}, {0, 7, 12, 0, 0, 2}},
        {{4, 0, 4, 8, 0, 2}, {4, 0, 4, 9, 0, 2}, {4, 0, 4, 10, 0, 2}, {4, 0, 4, 11, 0, 2}, {5, 0, 5, 12, 0, 2}},
        {{2, 0, 0, 0, 9, 4}, {2, 0, 0, 0, 10, 4}, {3, 0, 0, 0, 11, 4}, {3, 0, 0, 0, 12, 4}, {4, 0, 0, 0, 13, 4}}};

    const double driveCoefficients[6] = {-0.2, -0.1, 0, 0.1, 0.2, 0};

    int calculateDeltaX(int base, int sumPresentX, double prodFriends, double sumPresentTrain,
                        double coefDrive, int drive, double sumPresentDrivePlus, double UmaGrowthRate, int numSupportPresent)
    {
        return floor((base + sumPresentX) * prodFriends * (1 + 0.01 * sumPresentTrain) *
                     (1 + coefDrive * (1 + 0.01 * sumPresentDrivePlus)) *
                     (1 + 0.01 * UmaGrowthRate) * (1 + numSupportPresent * 0.05));
    }

    void readUmaMusume()
    {
        for (int i = 0; i < 5; ++i)
            cin >> uma.stats[i];
        for (int i = 0; i < 5; ++i)
            cin >> uma.grow[i];
    }

    void readSupportCards()
    {
        Cards.resize(6);
        for (auto &card : Cards)
        {
            cin >> card.friend_ >> card.drive_ >> card.train_;
            for (int i = 0; i < 5; ++i)
            {
                cin >> card.stats[i];
                uma.stats[i] += card.stats[i];
            }
            for (int i = 0; i < 5; ++i)
                cin >> card.statsPlus[i];
        }
        uma.init();
    }

    void readTrainings()
    {
        int n;
        cin >> n;
        trainings.resize(n);
        for (auto &training : trainings)
        {
            int S_size;
            cin >> training.summer >> training.weight >> training.drive >> training.type >> S_size;
            training.Cards.resize(S_size);
            for (auto &sc : training.Cards)
            {
                cin >> sc.first >> sc.second;
            }
        }
    }

    void simulateTrainings()
    {
        vector<int> trainingCount(6, 0);
        for (const auto &training : trainings)
        {
            int lv = training.summer ? 5 : 1;
            if (!training.summer)
            {
                lv += trainingCount[training.type] / 4;
                lv = min(lv, 5);
                ++trainingCount[training.type];
            }
            // cout << lv << '\n';

            int sumPresentPlus[6] = {0};
            double prodFriends = 1.0, sumPresentTrain = 0.0, sumPresentDrivePlus = 0.0;
            for (const auto &sc : training.Cards)
            {
                int cardIndex = sc.first - 1;
                bool isFriendshipTraining = sc.second;
                const auto &card = Cards[cardIndex];

                for (int i = 0; i < 6; ++i)
                    sumPresentPlus[i] += card.statsPlus[i];

                if (isFriendshipTraining)
                    prodFriends *= (1 + 0.01 * card.friend_);

                sumPresentTrain += card.train_;
                sumPresentDrivePlus += card.drive_;
            }

            for (int i = 0; i < 6; ++i)
            {
                int delta = calculateDeltaX(baseTrainingValues[training.type][lv - 1][i], sumPresentPlus[i], prodFriends,
                                            sumPresentTrain, driveCoefficients[training.drive], training.drive,
                                            sumPresentDrivePlus, uma.grow[i], training.Cards.size());

                if (training.weight == 1 && i == 0)
                    delta = 0;
                if (i < 5)
                    uma.stats[i] = min(1200, uma.stats[i] + delta);
                else
                    uma.stats[i] += delta;
            }

            for (int i = 0; i < 6; ++i)
                cout << uma.stats[i] << " ";
            cout << '\n';
        }
    }
};

int main()
{
    TrainingSimulator simulator;
    simulator.readUmaMusume();
    simulator.readSupportCards();
    simulator.readTrainings();
    simulator.simulateTrainings();
}
