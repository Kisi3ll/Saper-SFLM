#include "MSTextController.h"
#include "MinesweeperB.h"
#include "MSBoardTextView.h"

using namespace std;
MSTextController::MSTextController(Plansza &m_plansza, MSBoardTextView &m_widok): plansza(m_plansza), widok(m_widok){

}
void  MSTextController::play() {
    widok.display();
    while (plansza.getGameState()==RUNNING)
    {
        char wybor;
        int wiersz, kolumna;
        cout << "Wybierz wiersz i kolumne: " << endl;
        cin >> wiersz >> kolumna;
        //if(plansza.isOutofBoard(wiersz-1,kolumna-1)==false) continue;
        cout << "Co chcesz zrobić? \n";
        cout << "Odkryj pole [\"o\"] \n";
        cout << "Ustaw flage [\"f\"] \n";
        cin >> wybor;
        if (wybor=='o' || wybor=='O')
        {
            plansza.revealField(wiersz-1,kolumna-1);
        }
        else if(wybor=='f' || wybor=='F')
        {
            plansza.toggleFlag(wiersz-1,kolumna-1);
        }
        else continue;
        widok.display();

    }
    if(plansza.getGameState()==FINISHED_LOSS) cout << "Przegrales!" << endl;
    if(plansza.getGameState()==FINISHED_WIN) cout << "Gratulacje! Wygrales!" << endl;
}