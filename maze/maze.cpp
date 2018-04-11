#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>

using namespace std;

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* helper function for internal use only which gets the dimensions of a maze */
bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];

  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a maze from a file*/
char **load_maze(const char *filename, int &height, int &width) {

  bool success = get_maze_dimensions(filename, height, width);

  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);

  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }

  return m;
}

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0)
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";
    for (int c=0; c<width; c++)
      cout << m[r][c];
    cout << endl;
  }
}

bool find_marker(char ch, char **maze, int height, int width, int &row, int &column)
{
  for (row = 0; row < height; row++) {
    for(column = 0; column < width; column++)
    {
      if(maze[row][column] == ch)
        return true;
    }
  }
  return false;
}
void map_move(char ch, int &row, int &col)
{
  switch (ch) {
    case 'N': {row--; break;}
    case 'S': {row++; break;}
    case 'E': {col++; break;}
    case 'W': {col--; break;}
    default: {cout << "wrong input direction character!" << endl;}
  }
}
bool valid_solution(const char *path, char **maze, int height, int width)
{
  int in_row, in_col;
  if(!find_marker('>',maze, height, width, in_row, in_col))
  { cout << "cannot get entrance! "<<endl; return false;}
  while (path[0] != '\0') {
    map_move(path[0], in_row, in_col);
    if(maze[in_row][in_col] != ' ' && maze[in_row][in_col] != 'X')
      return false;
    path++;
  }
  if (maze[in_row][in_col] != 'X')
    return false;
  return true;
}

// function to find valid solution path through maze
// from start ch to end ch
// should be recursive
// const char* find_path(char** maze, int height, int width, char start, char end)
// {
// 	// allocate new path
// 	char *path = new char[512];
// 	path[0] = '\0';
//
// 	// pass path on as function parameter (easiest way i can think of)
// 	if (foundPath(maze, height, width, start, end, path))
// 		return path;
//
// 	return "no solution";
// }
//
// bool foundPath(char** maze, int height, int width, char start, char end, char* path)
// {
// 	int row, col, rowE, colE;
// 	bool starting = find_marker(start, maze, height, width, row, col);
// 	bool ending = find_marker(end, maze, height, width, rowE, colE);
//
// 	// base case, complete if contains no end markers in maze
// 	if (!ending)
// 		return true;
//
// 	// recursive step
// 	// If can go North
// 	if (row - 1 >= 0) {
// 		// if North block contains end
// 		if (maze[row - 1][col] == end)
// 		{
// 			// mark maze appropriately
// 			maze[row - 1][col] = '#';
// 			maze[row][col] = '#';
// 			strcat(path, "N");
// 			return foundPath(maze, height, width, start, end, path);
// 		}
//
// 		// if North block contains space
// 		else if (maze[row - 1][col] == ' ')
// 		{
// 			maze[row - 1][col] = start;
// 			maze[row][col] = '#';
// 			strcat(path, "N");
//
// 			// if deadend
// 			if(!foundPath(maze, height, width, start, end, path))
// 			{
// 				// forget this path
// 				maze[row - 1][col] = ' ';
// 				maze[row][col] = start;
// 				path[strlen(path) - 1] = '\0';
// 			} else {
// 				// not deadend, keep going
// 				return foundPath(maze, height, width, start, end, path);
// 			}
// 		}
// 	}
//
// 	// Other directions uses the same principle
// 	// South
// 	if (row + 1 < height) {
// 		if (maze[row + 1][col] == end) {
// 			maze[row + 1][col] = '#';
// 			maze[row][col] = '#';
// 			strcat(path, "S");
// 			return foundPath(maze, height, width, start, end, path);
// 		}
// 		else if (maze[row + 1][col] == ' ') {
// 			maze[row + 1][col] = start;
// 			maze[row][col] = '#';
// 			strcat(path, "S");
// 			if(!foundPath(maze, height, width, start, end, path)) {
// 				maze[row + 1][col] = ' ';
// 				maze[row][col] = start;
// 				path[strlen(path) - 1] = '\0';
// 			} else {
// 				return foundPath(maze, height, width, start, end, path);
// 			}
// 		}
// 	}
//
// 	// East
// 	if (col + 1 < width) {
// 		if (maze[row][col + 1] == end) {
// 			maze[row][col + 1] = '#';
// 			maze[row][col] = '#';
// 			strcat(path, "E");
// 			return foundPath(maze, height, width, start, end, path);
// 		} else if (maze[row][col + 1] == ' ') {
// 			maze[row][col + 1] = start;
// 			maze[row][col] = '#';
// 			strcat(path, "E");
// 			if(!foundPath(maze, height, width, start, end, path)) {
// 				maze[row][col + 1] = ' ';
// 				maze[row][col] = start;
// 				path[strlen(path) - 1] = '\0';
// 			} else {
// 				return foundPath(maze, height, width, start, end, path);
// 			}
// 		}
// 	}
//
// 	// West
// 	if (col - 1 >= 0) {
// 		if (maze[row][col - 1] == end) {
// 			maze[row][col - 1] = '#';
// 			maze[row][col] = '#';
// 			strcat(path, "W");
// 			return foundPath(maze, height, width, start, end, path);
// 		}
// 		else if (maze[row][col - 1] == ' ') {
// 			maze[row][col - 1] = start;
// 			maze[row][col] = '#';
// 			strcat(path, "W");
// 			if(!foundPath(maze, height, width, start, end, path)) {
// 				maze[row ][col - 1] = ' ';
// 				maze[row][col] = start;
// 				path[strlen(path) - 1] = '\0';
// 			} else {
// 				return foundPath(maze, height, width, start, end, path);
// 			}
// 		}
// 	}
//
// 	// all adjacent blocks are occupied
// 	return false;
// }
