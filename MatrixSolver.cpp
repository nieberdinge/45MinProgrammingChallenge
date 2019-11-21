#include <iostream>
#include <vector>

void printVector(std::vector<std::vector<float>> &matrix);
void makePivot(std::vector<std::vector<float>>& matrix);
void forwardPhase(std::vector<std::vector<float>>& matrix);

int main() {
	std::cout << "Hello Coding Challenge" << std::endl;
	std::cout << "This is the vector solver" << std::endl;

	std::vector<std::vector<float>> matrix;


	matrix.resize(2);
	matrix.at(0).push_back(2);
	matrix.at(0).push_back(4);
	matrix.at(1).push_back(1);
	matrix.at(1).push_back(5);

	printVector(matrix);

	makePivot(matrix);
	printVector(matrix);

	forwardPhase(matrix);
	printVector(matrix);

	if (matrix.at(1).at(1) != 1 && matrix.at(1).at(1) != 0) {
		matrix.at(1).at(1) /= matrix.at(1).at(1);
		std::cout << "Dividing Row 2 by " << matrix.at(1).at(1) << std::endl;
	}
	printVector(matrix);
	if (matrix.at(0).at(1) != 0) {
		float multiple = matrix.at(0).at(1);
		float newRowNum = matrix.at(1).at(0) * multiple;
		matrix.at(0).at(1) = 0;
		std::cout << "Subtracting Row 1 by Row " << multiple << " times Row 2" << std::endl;
	}
	printVector(matrix);



	
}

void forwardPhase(std::vector<std::vector<float>>& matrix) {
	for (int i = 1; i < matrix.size(); i++) {
		if (matrix.at(i).at(0) != 0) {
			float multiple = matrix.at(i).at(0);
			for (int k = 0; k < matrix.at(0).size(); k++) {
				float newRowNum = matrix.at(0).at(k) * multiple;
				matrix.at(i).at(k) -= newRowNum;

			}
			std::cout << "Subtracting Row " << i + 1 << " by Row " << multiple << " times Row 1" << std::endl;
		}

	}

}
void makePivot(std::vector<std::vector<float>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.at(i).size(); j++) {
			if (i == 0 &&  j == 0) {
				//Not already 1
				if (matrix.at(i).at(j) != 1) {
					if (matrix.at(i + 1).at(j) == 1) {
						matrix.at(i).swap(matrix.at(i + 1));
						std::cout << "Swaping Row " << i+1 << " and Row " << i + 2 << std::endl;
					}
					else {
						float divide = matrix.at(i).at(j);
						for (int k = 0; k < matrix.at(i).size(); k++) {
							matrix.at(i).at(k) /= divide;
						}
						std::cout << "Dividing row " << i+1 << " by " << divide << "." << std::endl;
					}
				}
			}
		}

	}
}

void printVector(std::vector<std::vector<float>> &matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		std::cout << "[";
		for (int j = 0; j < matrix.at(i).size(); j++) {
			std::cout << matrix.at(i).at(j) << " ";
		}
		std::cout << "]" << std::endl;
	}
}
