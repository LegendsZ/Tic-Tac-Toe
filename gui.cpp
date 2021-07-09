#include "gui.h"

int main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	TripleTsREVAMPED::gui form;
	System::Windows::Forms::Application::Run(% form);
	return 0;
}

System::Void TripleTsREVAMPED::gui::gui_Load(System::Object^ sender, System::EventArgs^ e)
{
	lblVersion->Text += version;

    btnArray = gcnew array<System::Windows::Forms::Button^>{btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9};

	srand(time(0));
    randomize_array(randomArray);

    if (botFirst) {
        randomize_array(randomArray);
        int changed = makeMove(0, randomArray);
        changeLogicGame(changed, -1);
    }

	return System::Void();
}

System::Void TripleTsREVAMPED::gui::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	return System::Void();
}

System::Void TripleTsREVAMPED::gui::btnGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ num_string = ((Button^)sender)->Name->ToString()->Substring(3);
    char num = num_string->ToCharArray()[0];

    ((Button^)sender)->Text = "X";
    changeLogicGame(num - '0' - 1, 1); //convs to its value (not ascii)
    if (applyLogic()) {
        return;
    }

    randomize_array(randomArray);

    int changed = makeMove(0, randomArray);
    changeLogicGame(changed, -1);
    if (applyLogic()) {
        return;
    }

	return System::Void();
}

void TripleTsREVAMPED::gui::randomize_array(int* randomized)
{
    int randomized_index = 0;

    for (int i = 0; i < 8; i++) {
        randomized[i] = -1;
    }

    while (randomized_index != 8) {
        int random = rand() % 8;
        bool notThere = true;
        for (int i = 0; i <= randomized_index; i++) {
            if (randomized[i] == random) {
                notThere = false;
            }
        }
        if (notThere == true) {
            randomized[randomized_index++] = random;
        }
    }
}

void TripleTsREVAMPED::gui::changeLogicGame(int toChange, int change)
{
    if (btnArray[toChange]->Text->ToCharArray()[0] == 'X') {
        countX++;
    }
    else if (btnArray[toChange]->Text->ToCharArray()[0] == 'O') {
        countO++;
    }
    if (toChange == 0 || toChange == 3 || toChange == 6) {
        eight[3] += change;
        if (toChange == 0) {
            eight[0] += change;
            eight[6] += change;
        }
        else if (toChange == 3) {
            eight[1] += change;
        }
        else if (toChange == 6) {
            eight[2] += change;
            eight[7] += change;
        }
    }
    else if (toChange == 1 || toChange == 4 || toChange == 7) {
        eight[4] += change;
        if (toChange == 1) {
            eight[0] += change;
        }
        else if (toChange == 4) {
            eight[7] += change;
            eight[6] += change;
            eight[1] += change;
        }
        else if (toChange == 7) {
            eight[2] += change;
        }
    }
    else if (toChange == 2 || toChange == 5 || toChange == 8) {
        eight[5] += change;
        if (toChange == 2) {
            eight[0] += change;
            eight[7] += change;
        }
        else if (toChange == 5) {
            eight[1] += change;
        }
        else if (toChange == 8) {
            eight[2] += change;
            eight[6] += change;
        }
    }
}

bool TripleTsREVAMPED::gui::applyLogic() {
    if (!(countX > 2 || countO > 2)) {
        return false;
    }

    bool space = false;

    for (int i = 0; i < 8; i++) {
        if (btnArray[i]->Text->ToCharArray()[0] == ' ') {
            space = true;
        }
        if (eight[i] == 3) {
            MessageBox::Show(gcnew String("WON!"));
            resetData();
            return true;
        }
        else if (eight[i] == -3) {
            MessageBox::Show(gcnew String("LOST!"));
            resetData();
            return true;
        }
    }
    if (btnArray[8]->Text->ToCharArray()[0] == ' ') {
        space = true;
    }
    if (space == false) {
        MessageBox::Show(gcnew String("TIE!"));
        resetData();
        return true;
    }
    return false;
}

int TripleTsREVAMPED::gui::makeMove(int startH, const int* randomized)
{
    int highest = rand() % 8;
    int lowest = rand() % 8;
    int picked = rand() % 8;

    for (int i = startH; i < 8; i++) {
        if (eight[randomized[i]] > eight[highest]) {
            highest = randomized[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        if (eight[randomized[i]] < eight[lowest]) {
            lowest = randomized[i];
        }
    }

    if (abs(eight[lowest]) == eight[highest]) {
        picked = lowest;
    }
    else {
        picked = highest;
    }

    int changed;

    if (picked >= 0 && picked <= 2) {
        switch (picked)
        {
        case 0:
            changed = makeMove_2(0, 2, 1);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        case 1:
            changed = makeMove_2(3, 5, 1);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        case 2:
            changed = makeMove_2(6, 8, 1);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        default:
            break;
        }
    }
    else if (picked >= 3 && picked <= 5) {
        switch (picked)
        {
        case 3:
            changed = makeMove_2(0, 6, 3);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        case 4:
            changed = makeMove_2(1, 7, 3);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        case 5:
            changed = makeMove_2(2, 8, 3);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        default:
            break;
        }
    }
    else if (picked >= 6) {
        switch (picked)
        {
        case 6:
            changed = makeMove_2(0, 8, 4);
            if (changed == -1) {
                return makeMove(picked + 1, randomized);
            }
            else {
                return changed;
            }
            break;
        case 7:
            return makeMove_2(2, 6, 2);
            break;
        default:
            break;
        }
    }
    return -1;
}

int TripleTsREVAMPED::gui::makeMove_2(int start, int end, int increment)
{
    int availables[3] = { -1,-1,-1 };
    int available_index = -1;

    for (int i = start; i < end + 1; i += increment) {
        System::Windows::Forms::Button^ btn = btnArray[i];
        if (btn->Text->ToCharArray()[0] == ' ') {
            availables[++available_index] = i;
        }
    }
    if (available_index == -1) {
        return -1;
    }
    int picked = rand() % (available_index + 1);
    btnArray[availables[picked]]->Text = "O";

    return availables[picked];
}

void TripleTsREVAMPED::gui::resetData() {
    for (int i = 0; i < 8; i++) {
        btnArray[i]->Text = " ";
        eight[i] = 0;
    }
    btnArray[8]->Text = " ";
    srand(time(0));
}




System::Void TripleTsREVAMPED::gui::pnlBack_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    isDragging = true;
    offset = e->Location;
    return System::Void();
}

System::Void TripleTsREVAMPED::gui::pnlBack_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    if (isDragging) {
        Point current = PointToScreen(Point(e->X, e->Y));
        Location = Point(current.X - offset.X, current.Y - offset.Y);
    }
}

System::Void TripleTsREVAMPED::gui::pnlBack_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    isDragging = false;
}