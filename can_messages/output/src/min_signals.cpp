#include "min_signals.h"

#include <sstream>

CAN_min_signals :: CAN_min_signals(){

	m_startMsgId=100;
	m_temperatureGetMsgId=m_startMsgId + 2;
	m_temperatureSetMsgId=m_startMsgId + 2 + 1:
	m_humidityGetMsgId=m_startMsgId + 4;
	m_humiditySetMsgId=m_startMsgId + 4 + 1;
}
std::string CAN_min_signals :: get_temperature() {
	std::stringstream sstream; 
	sstream << "{\"ID\": "<< m_temperatureGetMsgId
		<< ", \"length\":0 " 
		<< ", \"value\": \"\"; }" 
	return sstream.str(); 
} 
std::string CAN_min_signals :: set_temperature(float newValue) {
	std::stringstream sstream; 
	sstream << "{\"ID\": "<< m_temperatureSetMsgId
		<< ", \"length\":0 " 
		<< ", \"value\": \"\"; }" 
		<< newValue
	return sstream.str(); 
} 
std::string CAN_min_signals :: get_humidity() {
	std::stringstream sstream; 
	sstream << "{\"ID\": "<< m_humidityGetMsgId
		<< ", \"length\":0 " 
		<< ", \"value\": \"\"; }" 
	return sstream.str(); 
} 
std::string CAN_min_signals :: set_humidity(uint8_t newValue) {
	std::stringstream sstream; 
	sstream << "{\"ID\": "<< m_humiditySetMsgId
		<< ", \"length\":0 " 
		<< ", \"value\": \"\"; }" 
		<< newValue
	return sstream.str(); 
} 
