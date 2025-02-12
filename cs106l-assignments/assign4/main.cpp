/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
  std::vector<double>::const_iterator min_temp = std::min_element(dailyWeather.begin(), dailyWeather.end());
  std::vector<double>::const_iterator max_temp = std::max_element(dailyWeather.begin(), dailyWeather.end());
  double avg_temp = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / dailyWeather.size();
  return Forecast{*min_temp, *max_temp, avg_temp};
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */

  // solution 1
  // std::vector<Forecast> forecasts;
  // for (const auto& dailyWeather : weatherData) {
  //   forecasts.push_back(compute_forecast(dailyWeather));
  // }
  // return forecasts;

  // solution 2
  std::vector<Forecast> forecasts(weatherData.size());
  std::transform(weatherData.begin(), weatherData.end(), forecasts.begin(), compute_forecast);
  return forecasts;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
  std::vector<Forecast> filteredData = forecastData;
  filteredData.erase(
    std::remove_if(
      filteredData.begin(), filteredData.end(), 
      [](const Forecast &forecast) { 
        return (forecast.max_temp - forecast.min_temp) < kMaxTempRequirement
          || forecast.avg_temp < uAvgTempRequirement; 
      }
    ), 
    filteredData.end()
  );
  return filteredData;
}

std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData)
{
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
  std::random_device rd;
  std::mt19937 g(rd());
  std::vector<Forecast> shuffled_data = forecastData;
  std::shuffle(shuffled_data.begin(), shuffled_data.end(), g);
  return shuffled_data;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
  std::vector<Forecast> outputData = get_forecasts(weatherData);
  outputData = get_filtered_data(outputData);
  outputData = get_shuffled_data(outputData);
  return outputData;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"