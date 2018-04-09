#include <glm\glm.hpp>

#include <iostream>

void getDisplacementAndAngle(float throwAngle, float throwSpeed, float time, glm::vec2& displacement, float& finalAngle) {
	glm::vec2 velInitial = throwSpeed * glm::vec2{ glm::cos(throwAngle), glm::sin(throwAngle) };
	glm::vec2 acc = { 0, -9.81 };

	displacement = velInitial * time + 0.5f * acc * glm::pow(time, 2);

	glm::vec2 velFinal = velInitial + acc * time;
	finalAngle = glm::atan(velFinal.y, velFinal.x);
}

int main() {
	float throwAngle;
	float throwSpeed;
	float time;

	std::cout << "Throw Angle (radians): ";
	std::cin >> throwAngle;
	std::cout << "Throw Speed: ";
	std::cin >> throwSpeed;
	std::cout << "Time: ";
	std::cin >> time;

	glm::vec2 displacement;
	float finalAngle;
	getDisplacementAndAngle(throwAngle, throwSpeed, time, displacement, finalAngle);

	std::cout << "Displacement: <" << displacement.x << ", " << displacement.y << ">" << std::endl;
	std::cout << "Final angle: " << finalAngle << " radians" << std::endl;

	system("pause");
}