import {debounce} from 'lodash';
import React, {useCallback, useEffect, useState} from 'react';
import {
  Image,
  SafeAreaView,
  ScrollView,
  StatusBar,
  Text,
  TextInput,
  TouchableOpacity,
  View,
} from 'react-native';
import {
  CalendarDaysIcon,
  MagnifyingGlassIcon,
} from 'react-native-heroicons/outline';
import {MapPinIcon} from 'react-native-heroicons/solid';
import * as Progress from 'react-native-progress';
import {fetchLocations, fetchWeatherForecast} from '../api/weather';
const {weatherImages} = require('../constants/index');
import {theme} from '../theme/index';
// import {getData, storeData} from '../utils/asyncStorage';

export default function HomeScreen() {
  const [showSearch, toggleSearch] = useState(false);
  const [locations, setLocations] = useState([]);
  const [weather, setWeather] = useState({});
  const [loading, setLoading] = useState(true);

  const handleLocation = location => {
    setLocations([]);
    toggleSearch(false);
    setLoading(true);
    fetchWeatherForecast({
      cityName: location.name,
      days: '7',
    }).then(data => {
      setWeather(data);
      setLoading(false);
      // storeData('city', location.name);
    });
  };

  const handleSearch = value => {
    if (value.length > 3) {
      fetchLocations({cityName: value})
        .then(data => {
          setLocations(data);
        })
        .catch(err => {
          console.log(err);
        });
    }
  };

  useEffect(() => {
    fetchMyWeatherData();
  }, []);

  const fetchMyWeatherData = async () => {
    // let myCity = await getData('city');
    let cityName = 'Dibrugarh';
    // if (myCity) {
    //   cityName = myCity;
    // }
    fetchWeatherForecast({
      cityName,
      days: '7',
    }).then(data => {
      setWeather(data);
      setLoading(false);
    });
  };

  const handleTextDebounce = useCallback(debounce(handleSearch, 1000), []);

  const {current, location} = weather;

  return (
    <View className="flex-1 relative">
      <StatusBar style="light" />
      <Image
        blurRadius={50}
        source={require('../assets/images.jpg')}
        className="absolute h-full w-full"
      />
      {loading ? (
        <View className="flex-1 flex-row justify-center items-center">
          <Progress.CircleSnail thickness={10} size={140} color="#0bb3b2" />
        </View>
      ) : (
        <SafeAreaView className="flex flex-1">
          {/* search  */}
          <View style={{height: '7%'}} className="mx-4 relative z-50">
            <View
              className="flex-row justify-end items-center rounded-full"
              style={{
                backgroundColor: showSearch
                  ? theme.frostedGlass(0.2)
                  : 'transparent',
              }}>
              {showSearch ? (
                <TextInput
                  onChangeText={handleTextDebounce}
                  placeholder="Search city"
                  placeholderTextColor={'lightgray'}
                  className="pl-6 h-10 flex-1 text-base text-white "
                />
              ) : null}
              <TouchableOpacity
                onPress={() => toggleSearch(!showSearch)}
                style={{backgroundColor: theme.bgWhite(0.3)}}
                className="rounded-full p-3 m-1">
                <Text>
                  <MagnifyingGlassIcon size="24" color="white" />
                </Text>
              </TouchableOpacity>
            </View>
            {locations.length > 0 && showSearch ? (
              <View className="absolute w-full  bg-gray-300 top-16 rounded-3xl">
                {locations.map((location, index) => {
                  let showBorder = index + 1 != locations.length;
                  let borderClass = showBorder
                    ? 'border-b-2 border-b-gray-400'
                    : '';
                  return (
                    <TouchableOpacity
                      onPress={() => {
                        handleLocation(location);
                      }}
                      key={index}
                      className={
                        'flex-row items-center border-0 p-3 px-4 mb-1' +
                        borderClass
                      }>
                      <MapPinIcon size="20" color="gray" />
                      <Text className="text-black text-lg ml-2">
                        {location?.name} &#44;&nbsp; {location?.country}
                      </Text>
                    </TouchableOpacity>
                  );
                })}
              </View>
            ) : null}
          </View>
          {/* forecast */}
          <View className="mx-4 flex justify-around flex-1 mb-2 ">
            <Text className="text-white text-center text-2xl font-bold">
              {location?.name}&#44;&nbsp;
              <Text className="text-xl font-semibold text-gray-300">
                {location?.country}
              </Text>
            </Text>
            {/* weatherImage */}
            <View className="flex-row justify-center items-center">
              <Image
                source={weatherImages[current?.condition?.text]}
                className="h-52 w-52"
              />
            </View>
            {/* degree celsius */}

            <View className="space-y-2">
              <Text className="text-white text-center text-6xl font-bold ml-5">
                {current?.temp_c}&#176;
              </Text>
              <Text className="text-white text-center text-xl tracking-widest ">
                {current?.condition?.text}
              </Text>
            </View>
            {/* other stuff */}
            <View className="flex-row justify-between mx-4">
              <View className="flex-row space-x-2 items-center">
                <Image
                  source={require('../assets/wind.png')}
                  className="h-6 w-6"
                />
                <Text className="text-white font-semibold text-base">
                  {current?.wind_kph} km/h
                </Text>
              </View>
              <View className="flex-row space-x-2 items-center">
                <Image
                  source={require('../assets/drop.png')}
                  className="h-6 w-6"
                />
                <Text className="text-white font-semibold text-base">
                  {current?.humidity}%
                </Text>
              </View>
              <View className="flex-row space-x-2 items-center">
                <Image
                  source={require('../assets/sun.png')}
                  className="h-6 w-6"
                />
                <Text className="text-white font-semibold text-base">
                  {weather?.forecast?.forecastday[0]?.astro?.sunrise}
                </Text>
              </View>
            </View>
          </View>
          <View className="mb-2 space-y-3">
            <View className="flex-row items-center mx-5 space-x-2">
              <CalendarDaysIcon size="22" color="white" />
              <Text className="text-white text-base ">Daily Forecast</Text>
            </View>
            <ScrollView
              horizontal
              contentContainerStyle={{paddingHorizontal: 15}}
              showsHorizontalScrollIndicator={false}>
              {weather?.forecast?.forecastday?.map((item, index) => {
                let date = new Date(item.date);
                let options = {weekday: 'short'};
                let dayName = date.toLocaleDateString('en-US', options);
                dayName = dayName.split(',')[0];
                return (
                  <View
                    key={index}
                    className="flex justify-center items-center w-24 rounded-3xl py-3 spacx-y-1 mr-4"
                    style={{backgroundColor: theme.frostedGlass(0.15)}}>
                    <Image
                      source={weatherImages[item?.day?.condition?.text]}
                      className="h-11 w-11"
                    />
                    <Text className="text-white text-base">{dayName}</Text>
                    <Text className="text-white text-xl font-semibold">
                      {item?.day?.avgtemp_c}&#176;
                    </Text>
                  </View>
                );
              })}
            </ScrollView>
          </View>
        </SafeAreaView>
      )}
    </View>
  );
}
