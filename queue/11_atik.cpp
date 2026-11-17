#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Doctor {
    string name;
    string hospital;
    string contact;
};

void pressEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

bool checkBack(char ch) {
    return (ch == 'B' || ch == 'b');
}

vector<Doctor> getDoctors() {
    vector<Doctor> doctors;
    doctors.push_back({"Dr. Mosharraf Ahmed Khasru", "Azgar Ali Hospital, Dhaka", "Contact via hospital"});
    doctors.push_back({"Prof. Dr. Hasibur Rahman", "Evercare Hospital Dhaka", "Contact via hospital"});
    doctors.push_back({"Dr. Asif Imran Siddiqui", "Skinic Dermatology Centre, Dhaka", "Contact via clinic"});
    return doctors;
}

// ================= Skin Type Selection =================
void skinTypeSelection() {
    char input;
    int attempts = 0;

    while (attempts < 3) {
        cout << "\nSKIN TYPE SELECTION:\n";
        cout << "----------------------\n\n";
        cout << "1. Normal\n2. Dry\n3. Oily\n4. Combination\n5. Sensitive\n";
        cout << "Select your skin type (1-5) or B to go back: ";
        cin >> input;
        if (checkBack(input)) return;

        int choice = input - '0';
        if (choice >= 1 && choice <= 5) {
            cout << "\nRecommended Products for ";

            switch (choice) {
                case 1:
                    cout << "Normal Skin:\nGentle Foaming Cleanser\nBalanced Moisturizer\nSPF 30 Sunscreen\n";
                    cout << "Seasonal Tips:\n- Summer: Gel-based moisturizer & sunscreen\n- Winter: Cream moisturizer\n- Monsoon: Clean twice daily\n";
                    break;
                case 2:
                    cout << "Dry Skin:\nHydrating Cleanser\nHyaluronic Acid Serum\nRich Cream Moisturizer\n";
                    cout << "Seasonal Tips:\n- Winter: Heavy moisturizer\n- Summer: Hydrating mist\n- Monsoon: Light cream\n";
                    break;
                case 3:
                    cout << "Oily Skin:\nSalicylic Acid Face Wash\nOil-free Gel Moisturizer\nClay Mask\n";
                    cout << "Seasonal Tips:\n- Summer: Wash twice daily\n- Monsoon: Clay mask weekly\n- Winter: Moisturize even if oily\n";
                    break;
                case 4:
                    cout << "Combination Skin:\nMild Cleanser\nBalancing Toner\nLightweight Moisturizer\n";
                    cout << "Seasonal Tips:\n- Summer: Gel on oily areas\n- Winter: Cream on dry areas\n- Monsoon: Avoid heavy T-zone products\n";
                    break;
                case 5:
                    cout << "Sensitive Skin:\nFragrance-free Cleanser\nSoothing Aloe Vera Gel\nCalming Cream\n";
                    cout << "Seasonal Tips:\n- Summer: Avoid direct sun\n- Winter: Barrier-repair moisturizer\n- Monsoon: Avoid new products\n";
                    break;
            }

            pressEnter();
            return;
        } else {
            attempts++;
            cout << "Invalid choice! (" << attempts << "/3 attempts)\n";
        }
    }
}

// ================= Identify Skin Type =================
void identifySkinType() {
    while (true) {
        char start;
        cout << "\nIDENTIFY SKIN TYPE:\n------------------\n";
        cout << "Press any key to start or B to go back: ";
        cin >> start;
        if (checkBack(start)) return;

        char oilyAns, tightAns, breakoutAns, flakyAns;

        cout << "Answer with y/n or B to go back:\n";

        cout << "Is your face oily after a few hours? ";
        cin >> oilyAns;
        if (checkBack(oilyAns)) continue; // go back to start of this option
        oilyAns = tolower(oilyAns);

        cout << "Does your skin feel tight after washing? ";
        cin >> tightAns;
        if (checkBack(tightAns)) continue;
        tightAns = tolower(tightAns);

        cout << "Do you often have breakouts? ";
        cin >> breakoutAns;
        if (checkBack(breakoutAns)) continue;
        breakoutAns = tolower(breakoutAns);

        cout << "Do you notice dry, flaky patches? ";
        cin >> flakyAns;
        if (checkBack(flakyAns)) continue;
        flakyAns = tolower(flakyAns);

        cout << "\nYour Skin Type: ";
        if (oilyAns == 'y' && breakoutAns == 'y')
            cout << "Oily Skin\n";
        else if (tightAns == 'y' && flakyAns == 'y')
            cout << "Dry Skin\n";
        else if (oilyAns == 'y' && tightAns == 'y')
            cout << "Combination Skin\n";
        else if (oilyAns == 'n' && tightAns == 'n')
            cout << "Normal Skin\n";
        else
            cout << "Sensitive Skin\n";

        pressEnter();
        return;
    }
}

// ================= Skin Problem & Doctor =================
void skinProblem() {
    vector<Doctor> doctors = getDoctors();
    while (true) {
        char input;
        cout << "\nSKIN PROBLEM & DOCTOR SUGGESTION:\n---------------------------------\n";
        cout << "1. Acne or Pimples\n2. Redness or Rash\n3. Pigmentation\n4. Severe Dryness\n";
        cout << "Select problem (1-4) or B to go back: ";
        cin >> input;
        if (checkBack(input)) return;
        int choice = input - '0';

        cout << "\nSuggestion:\n";

        switch (choice) {
            case 1:
                cout << "Use salicylic acid cleanser and avoid touching pimples.\n";
                cout << "Doctor: " << doctors[0].name << ", " << doctors[0].hospital << "\n";
                break;
            case 2:
                cout << "Use soothing aloe vera gel and avoid harsh products.\n";
                cout << "Doctor: " << doctors[1].name << ", " << doctors[1].hospital << "\n";
                break;
            case 3:
                cout << "Use Vitamin C serum and apply sunscreen daily.\n";
                cout << "Doctor: " << doctors[2].name << ", " << doctors[2].hospital << "\n";
                break;
            case 4:
                cout << "Use thick moisturizer and drink plenty of water.\n";
                cout << "Doctor: " << doctors[0].name << ", " << doctors[0].hospital << "\n";
                break;
            default:
                cout << "Invalid choice!\n";
                continue; // loop again
        }
        pressEnter();
        return;
    }
}

// ================= Daily Routine =================
void dailyRoutine() {
    while (true) {
        char input;
        cout << "\nDAILY SKIN CARE ROUTINE:\n------------------------\n";
        cout << "Select skin type (1-5) or B to go back: ";
        cin >> input;
        if (checkBack(input)) return;
        int type = input - '0';

        switch (type) {
            case 1:
                cout << "Morning: Cleanser, Moisturizer, Sunscreen\nNight: Cleanser, Toner, Light cream\n";
                break;
            case 2:
                cout << "Morning: Hydrating Cleanser, Serum, Rich Cream\nNight: Cleanser, Facial Oil, Sleep Mask\n";
                break;
            case 3:
                cout << "Morning: Gel Cleanser, Oil-Free Moisturizer, Sunscreen\nNight: Cleanser, Clay Mask, Toner\n";
                break;
            case 4:
                cout << "Morning: Mild Cleanser, Toner, Moisturizer\nNight: Cleanser, Serum, Light Cream\n";
                break;
            case 5:
                cout << "Morning: Fragrance-Free Cleanser, Aloe Moisturizer, SPF\nNight: Cleanser, Soothing Cream\n";
                break;
            default:
                cout << "Invalid choice!\n";
                continue;
        }
        pressEnter();
        return;
    }
}

// ================= Ingredient Checker =================
void ingredientChecker() {
    vector<pair<string,string>> harmful = {
        {"Alcohol","Can dry out skin and cause irritation."},
        {"Sulfate","Harsh cleanser, may damage skin barrier."},
        {"Paraben","Preservative, may trigger allergies."},
        {"Fragrance","May cause irritation or allergic reactions."},
        {"Mineral Oil","Can block pores and cause acne."},
        {"Propylene Glycol","May irritate sensitive skin."},
        {"Synthetic Color / Dye","Can cause allergies or rashes."},
        {"Formaldehyde","Can irritate skin and is a potential carcinogen."},
        {"Phthalates","May disrupt hormones and cause skin problems."}
    };

    vector<string> presentIngredients;
    while (true) {
        char start;
        cin.ignore();
        cout << "\nPRODUCT INGREDIENT CHECKER\n-------------------------\n";
        cout << "Press any key to start or B to go back: ";
        cin >> start;
        if (checkBack(start)) return;

        for (auto &item : harmful) {
            char ans;
            cout << item.first << "? (y/n or B to go back): ";
            cin >> ans;
            if (checkBack(ans)) return;
            ans = tolower(ans);
            if (ans == 'y') presentIngredients.push_back(item.first + ": " + item.second);
        }

        cout << "\nResult:\n";
        if (presentIngredients.empty())
            cout << "Safe: No harmful ingredients detected.\n";
        else {
            cout << "Warning! Harmful ingredients:\n";
            for (auto &msg : presentIngredients) cout << "- " << msg << "\n";
        }
        pressEnter();
        return;
    }
}

// ================= Seasonal Tips =================
void showTips() {
    while (true) {
        char input;
        cout << "\nSEASONAL SKIN CARE TIPS\n-----------------------\n";
        cout << "1. Summer\n2. Winter\n3. Monsoon\nSelect season or B to go back: ";
        cin >> input;
        if (checkBack(input)) return;
        int choice = input - '0';

        switch(choice) {
            case 1:
                cout << "Summer Tips:\n- Oil-free sunscreen\n- Wash face twice\n- Stay hydrated\n"; break;
            case 2:
                cout << "Winter Tips:\n- Heavy moisturizer\n- Avoid hot showers\n- Lip balm regularly\n"; break;
            case 3:
                cout << "Monsoon Tips:\n- Keep skin clean and dry\n- Antifungal face wash\n- Avoid oily creams\n"; break;
            default:
                cout << "Invalid choice!\n"; continue;
        }
        pressEnter();
        return;
    }
}

// ================= Main =================
int main() {
    int choice;
    do {
        system("cls");
        cout << "\n==============================\n";
        cout << " WELCOME TO SKINBUDDY \n";
        cout << "==============================\n";
        cout << "1. Skin Type Selection\n2. Identify My Skin Type\n3. Skin Problem & Doctor Suggestion\n";
        cout << "4. Daily Skin Care Routine\n5. Product Ingredient Checker\n6. Seasonal Skin Tips\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: skinTypeSelection(); break;
            case 2: identifySkinType(); break;
            case 3: skinProblem(); break;
            case 4: dailyRoutine(); break;
            case 5: ingredientChecker(); break;
            case 6: showTips(); break;
            case 0: cout << "\nThank you for using SkinBuddy! Stay beautiful!\n"; break;
            default: cout << "Invalid choice!\n"; pressEnter();
        }
    } while(choice != 0);
    return 0;
}
