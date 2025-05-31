#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#define MAX_NUMBER 50
#define MIN_NUMBER 1
#define NB_NUMBER 5

#define MAX_STAR 12
#define MIN_STAR 1
#define NB_STAR 2

bool number_in_grid(int nb, std::vector<int> grid) {
    for (unsigned long i = 0; i < grid.size(); i++)
        if (grid[i] == nb)
            return true;
    return false;
}

int new_number(std::vector<int> grid) {
	int nb = 0;

	nb = rand() % (MAX_NUMBER - MIN_NUMBER) + MIN_NUMBER;
	while (number_in_grid(nb, grid))
	    nb = rand() % (MAX_NUMBER - MIN_NUMBER) + MIN_NUMBER;
	return nb;
}

int new_star(std::vector<int> grid) {
    int nb = 0;

	nb = rand() % (MAX_STAR - MIN_STAR) + MIN_STAR;
	while (number_in_grid(nb, grid))
	    nb = rand() % (MAX_STAR - MIN_STAR) + MIN_STAR;
	return nb;
}

std::vector<int> get_grid(std::vector<int> favorites, std::vector<int> fav_stars) {
	std::vector<int> grid;
	std::vector<int> stars;

	for (unsigned long i = 0; i < favorites.size(); i++)
	    if (!number_in_grid(favorites[i], grid))
	        grid.push_back(favorites[i]);
	while (grid.size() < NB_NUMBER)
	    grid.push_back(new_number(grid));
	std::sort(grid.begin(), grid.end());

	for (unsigned long i = 0; i < fav_stars.size(); i++)
	    if (!number_in_grid(fav_stars[i], stars))
	        stars.push_back(fav_stars[i]);
	while (stars.size() < NB_STAR)
	    stars.push_back(new_star(stars));
	std::sort(stars.begin(), stars.end());

	for (unsigned long i = 0; i < stars.size(); i++)
	    grid.push_back(stars[i]);
	return grid;
}

int main(void) {
	std::vector<int> favorites;
	std::vector<int> fav_stars;
	std::vector<int> grid;
	int nb = 1;

	srand(time(NULL));
	for (int i = 0; i < nb; i++) {
	    grid = get_grid(favorites, fav_stars);
		std::cout << "Grid number " << i + 1 << ":" << std::endl;
		std::cout << "Numbers:" << std::endl;
		for (int j = 0; j < NB_NUMBER; j++)
		    std::cout << grid[j] << " ";
		std::cout << std::endl;
		std::cout << "Stars:" << std::endl;
		for (unsigned long j = NB_NUMBER; j < grid.size(); j++)
		    std::cout << grid[j] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
