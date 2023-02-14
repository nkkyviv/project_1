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

		/*
		get the front sensor status (enabled/disabled)
		*/
		std::string get_front_sensor_status(); 
		/*
		set the front sensor status (enabled/disabled)
		*/
		std::string set_front_sensor_status(bool newValue); 

		/*
		get the flow rate in milliliter per second
		*/
		std::string get_flow_rate(); 
		/*
		set the flow rate in milliliter per second
		*/
		std::string set_flow_rate(uint16_t newValue); 

		/*
		get the flow meter sensor status
		*/
		std::string get_flow_meter_sensor_status(); 
		/*
		set the flow meter sensor status
		*/
		std::string set_flow_meter_sensor_status(uint8_t newValue); 

		/*
		get the light intensity percentage
		*/
		std::string get_light_intensity(); 
		/*
		set the light intensity percentage
		*/
		std::string set_light_intensity(uint8_t newValue); 

		/*
		get the light intensity sensor status
		*/
		std::string get_light_intensity_sensor_status(); 
		/*
		set the light intensity sensor status
		*/
		std::string set_light_intensity_sensor_status(uint8_t newValue); 

		/*
		get the water level percentage
		*/
		std::string get_water_level(); 
		/*
		set the water level percentage
		*/
		std::string set_water_level(uint8_t newValue); 

		/*
		get the water level sensor status
		*/
		std::string get_water_level_sensor_status(); 
		/*
		set the water level sensor status
		*/
		std::string set_water_level_sensor_status(uint8_t newValue); 

		/*
		get the soil moisture percentage
		*/
		std::string get_soil_moisture(); 
		/*
		set the soil moisture percentage
		*/
		std::string set_soil_moisture(uint8_t newValue); 

		/*
		get the soil moisture sensor status
		*/
		std::string get_soil_moisture_sensor_status(); 
		/*
		set the soil moisture sensor status
		*/
		std::string set_soil_moisture_sensor_status(uint8_t newValue); 

		/*
		get The 'Stop' light (enabled/disabled)
		*/
		std::string get_stop_signal_light(); 
		/*
		set The 'Stop' light (enabled/disabled)
		*/
		std::string set_stop_signal_light(bool newValue); 

	private:
	 uint8_t m_startMsgId;
	 float m_temperatureGetMsgId;
	 float m_temperatureSetMsgId;
	 uint8_t m_humidityGetMsgId;
	 uint8_t m_humiditySetMsgId;
	 bool m_front_sensor_statusGetMsgId;
	 bool m_front_sensor_statusSetMsgId;
	 uint16_t m_flow_rateGetMsgId;
	 uint16_t m_flow_rateSetMsgId;
	 uint8_t m_flow_meter_sensor_statusGetMsgId;
	 uint8_t m_flow_meter_sensor_statusSetMsgId;
	 uint8_t m_light_intensityGetMsgId;
	 uint8_t m_light_intensitySetMsgId;
	 uint8_t m_light_intensity_sensor_statusGetMsgId;
	 uint8_t m_light_intensity_sensor_statusSetMsgId;
	 uint8_t m_water_levelGetMsgId;
	 uint8_t m_water_levelSetMsgId;
	 uint8_t m_water_level_sensor_statusGetMsgId;
	 uint8_t m_water_level_sensor_statusSetMsgId;
	 uint8_t m_soil_moistureGetMsgId;
	 uint8_t m_soil_moistureSetMsgId;
	 uint8_t m_soil_moisture_sensor_statusGetMsgId;
	 uint8_t m_soil_moisture_sensor_statusSetMsgId;
	 bool m_stop_signal_lightGetMsgId;
	 bool m_stop_signal_lightSetMsgId;
};
#endif //HEADER_MIN_SIGNALS_H