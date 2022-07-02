#include <iostream>
#include <cstdint>

using namespace std;

class RGBA {
private:
	uint8_t m_red, m_green, m_blue, m_alpha;
public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
	
	void print() {
		cout << "red: " << static_cast<int>(m_red) << ", green: " << static_cast<int>(m_green)
			<< ", blue: " << static_cast<int>(m_blue) << ", alpha: " << static_cast<int>(m_alpha) << endl;
	}
};

int main(int argc, char const *argv[]) {
	RGBA color(0, 135, 135);
	color.print();

	return 0;
}
