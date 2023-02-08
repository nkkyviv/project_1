#ifndef HEADER_MIN_SIGNALS_H
#define HEADER_MIN_SIGNALS_H
#include <sstream>

class CAN_min_signals {
	public:
		CAN_min_signals();
		/*
		get the ambient temperature
		*/
		std::string get_temperature(); 
		/*
		set the ambient temperature
		*/
		std::string set_temperature(float newValue); 

		/*
		get the ambient humidity percentage
		*/
		std::string get_humidity(); 
		/*
		set the ambient humidity percentage
		*/
		std::string set_humidity(uint8_t newValue); 

	private:
	 uint8_t m_startMsgId;
	 uint8_t m_temperatureGetMsgId;
	 uint8_t m_temperatureSetMsgId;
	 uint8_t m_humidityGetMsgId;
	 uint8_t m_humiditySetMsgId;
};
#endif //HEADER_MIN_SIGNALS_H