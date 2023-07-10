#include "util/motor.h"

Motor::Motor(int id, double calibrationOffset) : _id(id), _offset(calibrationOffset)
{

}

/**
 * Move to position pos, where 0 is fully counterclockwise, and 180 is fully clockwise
*/
void Motor::moveToPosition(double pos, double speed, double duration)
{
	// format: #<id>P<pw>S<spd>T<time>
	//   where id = pin number, pw = pulse width, spd = movement speed in us/s, 
	//     time = time in us from current to target
	// range of motion: 400us to 1500-1900us
	Serial.print("#");
	Serial.print(_id);
	Serial.print("P");
	Serial.print(400 + 1100 * pos / 180 + _offset);
	if (speed > 0)
	{
		Serial.print("S");
		Serial.print(speed);
	}
	if (duration > 0) {
		Serial.print("T");
		Serial.print(duration);
	}
	Serial.println();
}
