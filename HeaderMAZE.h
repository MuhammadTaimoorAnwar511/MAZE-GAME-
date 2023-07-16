#include<iostream>
#include<fstream>
using namespace std;
class node
{
public:
    char node_row;
    char node_col;
    node* next;
    node(char r, char c)
    {
        node_row = r;
        node_col = c;
        next = NULL;
    }

};

class linked
{
public:
    node* head;
    node* current;
    int count;
    linked()
    {
        count = 0;
        head = NULL;
        current = NULL;
    }

    void insert_node_right(char r,char c)
    {
        node* n = new node(r,c);

        if (head == NULL)
        {
            ++count;
           
            head = n;
            current = n;
            return;
        }

        else
        {
            ++count;
            node* temp = head;
            //cout << "else run\n";
            while (temp->next != NULL)
            {
                temp = temp->next;
                //	cout << "while run\n";
            }
            temp->next = n;
            current = n;
        }
    }
    void display_node_path()
    {

        node* temp = head;

        while (temp != NULL)
        {
            cout << (int)temp->node_row << " " << (int)temp->node_col << "\n";
            //cout << temp->node_number << " " << temp->line << "\n";
            temp = temp->next;
        }
    }
    void display_current()
    {
        node* temp = current;
        cout << (int)temp->node_row << "  " << (int)temp->node_col<<"\n";

    }

    char get_current_row()
    {
        node* temp=current;

        return (int)temp->node_row;
    }

    char get_current_col()
    {
        node* temp = current;

        return (int)temp->node_col;
    }

    void delete_current()
    {
        node* temp=head;
        node* del = current;

        while (temp->next != current)
        {
            temp = temp->next;
        }

        delete del;

        current = temp;
        current->next = NULL;
        cout << (int)temp->node_row << "  " << (int)temp->node_col << "\n";
    }
};

void find_path(char **maze,char row,char col)
{
    linked l;
    int steps=1;
	cout << "\n__________________________\n";
	for (int i = 0; i < row; i++)
	{
		cout << "| ";
		for (int j = 0; j < col; j++)
		{
			cout << maze[i][j] << " |";
		}
		cout << endl;
	}
	cout << "\n--------------------------\n";
  
    int r = 0, c = 0;
    bool r_block = 1;//0 block //1 open//
    bool l_block = 1;
    bool u_block = 1;
    bool d_block = 1;

    int c_r;//current row//
    int c_c;//current column//
    int sl_r;//second last row//
    int sl_c;//second last col//
    bool found = 0;
    int count = 0;

      while (maze[r][c] != 'E' || steps!=0)//jab tak exit nhi mill jata 
   // while (count != 60)
    {
          if (count == 0)
          {
              steps = 0;
          }
        count++;

        if (r <= 7 && c <= 7)//possiblity of moving right
        {
            if (c == 7)//border//
            {
                r_block = 0;
            }
            else if (maze[r][c + 1] == 'E')//exit//
            {
                maze[r][c + 1] = 'E';
                r_block = 1;// open//
                c = c + 1;

                c_c = c;//current column//
                c_r = r;//current row//

                sl_c = c_c - 1;//second last col//
                sl_r = c_r;// second last row//
                found = 1;
                break;
            }
            else if (maze[r][c + 1] == ' ')//empty space//
            {
                //maze[0][0] = 'M';
                ++steps;
                maze[r][c + 1] = 'M';
                r_block = 1;// open//
                c = c + 1;

                c_c = c;//current column//
                c_r = r;//current row//
                // << " current -> -> ->" << c_r << " " << c_c << endl;
                l.insert_node_right(c_r,c_c);

                sl_c = c_c - 1;//second last col//
                sl_r = c_r;// second last row//

                // output //
                cout << "\n______________\n";
                for (int r = 0; r < 8; r++)
                {
                    cout << "| ";
                    for (int c = 0; c < 8; c++)
                    {
                        cout << maze[r][c] << " |";
                    }
                    cout << endl;
                }
                cout << "______________\n";
                cout << "\nRIGHT  \n";
                //close//
            }
            else if (maze[r][c + 1] == '1' || maze[r][c + 1] == 'M' || maze[r][c + 1] == 'R' || maze[r][c + 1] == 'S')//way block//
            {
                r_block = 0;//block//
                //cout << "\nRIGHT BLOCKED\n";
            }

        }

        if (r <= 7 && c >= 0)//possiblity of moving left
        {
            if (c == 0)
            {
                l_block = 0;
            }
            else if (maze[r][c - 1] == 'E')
            {
                maze[r][c - 1] = 'E';
                l_block = 1;//open
                c = c - 1;
                c_c = c;//current column//
                c_r = r;//current row//

                sl_c = c_c + 1;//second last col//
                sl_r = c_r;// second last row//
                found = 1;
                break;
            }
            else if (maze[r][c - 1] == ' ')
            {
                ++steps;
                //maze[0][0] = 'M';
                maze[r][c - 1] = 'M';
                l_block = 1;//open
                c = c - 1;
                c_c = c;//current column//
                c_r = r;//current row//
                l.insert_node_right(c_r, c_c);
                sl_c = c_c + 1;//second last col//
                sl_r = c_r;// second last row//

                // output //
                cout << "\n______________\n";
                for (int r = 0; r < 8; r++)
                {
                    cout << "| ";
                    for (int c = 0; c < 8; c++)
                    {
                        cout << maze[r][c] << " |";
                    }
                    cout << endl;
                }
                cout << "______________\n";
                cout << "\nLEFT  \n";
                //close//
            }
            else if (maze[r][c - 1] == '1' || maze[r][c - 1] == 'M' || maze[r][c - 1] == 'R' || maze[r][c - 1] == 'S')
            {
                l_block = 0;//block
                //cout << "\n LEFT BLOCKED\n";
            }
        }



        if (r >= 0 && c <= 7)//possiblity of moving up
        {
            if (r == 0)
            {
                u_block = 0;
            }
            else if (maze[r - 1][c] == 'E')
            {
                maze[r - 1][c] = 'E';
                u_block = 1;//open
                r = r - 1;
                c_c = c;//current column//
                c_r = r;//current row//
               
                sl_c = c_c;//second last col//
                sl_r = c_r + 1;// second last row//
                found = 1;
                break;
            }
            else if (maze[r - 1][c] == ' ')
            {
                ++steps;
                //maze[0][0] = 'M';
                maze[r - 1][c] = 'M';
                u_block = 1;//open
                r = r - 1;
                c_c = c;//current column//
                c_r = r;//current row//
                l.insert_node_right(c_r, c_c);
                sl_c = c_c;//second last col//
                sl_r = c_r + 1;// second last row//

                // output //
                cout << "\n______________\n";
                for (int r = 0; r < 8; r++)
                {
                    cout << "| ";
                    for (int c = 0; c < 8; c++)
                    {
                        cout << maze[r][c] << " |";
                    }
                    cout << endl;
                }
                cout << "______________\n";
                cout << "\nUP  \n";
                //close//   
            }
            else if (maze[r - 1][c] == '1' || maze[r - 1][c] == 'M' || maze[r - 1][c] == 'R' || maze[r - 1][c] == 'S')
            {
                u_block = 0;//block//
                //cout << "\nUP BLOCKED\n";
            }
        }



        if (r <= 7 && c <= 7)//possiblity of moving down
        {
            if (r == 7)
            {
                d_block = 0;//block//
            }
            else if (maze[r + 1][c] == 'E')
            {
                maze[r + 1][c] = 'E';
                d_block = 1;//open//
                r = r + 1;
                c_c = c;//current column//
                c_r = r;//current row//
              
                sl_c = c_c;//second last col//
                sl_r = c_r - 1;// second last row//
                found = 1;
                break;
            }
            else if (maze[r + 1][c] == ' ')
            {
                ++steps;
               // maze[0][0] = 'M';
                maze[r + 1][c] = 'M';
                d_block = 1;//open//
                r = r + 1;
                c_c = c;//current column//
                c_r = r;//current row//
                l.insert_node_right(c_r, c_c);
                sl_c = c_c;//second last col//
                sl_r = c_r - 1;// second last row//

                // output //
                cout << "\n______________\n";
                for (int r = 0; r < 8; r++)
                {
                    cout << "| ";
                    for (int c = 0; c < 8; c++)
                    {
                        cout << maze[r][c] << " |";
                    }
                    cout << endl;
                }
                cout << "______________\n";
                cout << "\nDOWN  \n";
                //close//
            }
            else if (maze[r + 1][c] == '1' || maze[r + 1][c] == 'M' || maze[r + 1][c] == 'R' || maze[r + 1][c] == 'S')
            {
                d_block = 0;//block
                //cout << "\ndown BLOCKED\n";
            }
        }


        //cout << "\n=================================\n";
        //cout << "r_block" << r_block << endl;
        //cout << "l_block" << l_block << endl;
        //cout << "u_block" << u_block << endl;
        //cout << "d_block" << d_block << endl;
        //cout << "\n=================================\n";
       

        if (r_block == 0 && l_block == 0 && u_block == 0 && d_block == 0)// every direction is BLOCK stuck//
        {
            if (steps != 0)
            {
                r_block = 1;
                l_block = 1;
                u_block = 1;
                d_block = 1;
                // cout << "\ncurrent row" << c_r << endl;
                // cout << "current col  " << c_c << endl;
                // cout << "second last row" << sl_r << endl;
                 //cout << "second last col" << sl_c << endl;
                c_r = l.get_current_row();
                c_c = l.get_current_col();
                maze[c_r][c_c] = 'R';
                l.delete_current();
                cout << "\nTAKE REVERSE \n";
                r = l.get_current_row();
                c = l.get_current_col();
               
                --steps;
                //r = sl_r;
                //c = sl_c;
            }
        }
    }

    cout << "\n##########################\n";
    cout << "\n______________\n";
    
    for (int r = 0; r < 8; r++)
    {
        cout << "| ";
        for (int c = 0; c < 8; c++)
        {
            cout << maze[r][c] << " |";
        }
        cout << endl;
    }

    cout << "______________\n";
    if (found == 1)
    {
        cout << "\nESCAPE PATH FOUND\n";
    }
    else
    {
        cout << "\nESCAPE PATH  NOT FOUND\n";
    }

   
    cout << "\n*****************\n";
    l.display_node_path();
    cout << "\n===========================\n";
    cout<<"movements   " << steps << endl;
}