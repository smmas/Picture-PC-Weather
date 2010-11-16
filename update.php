<?php
	require_once('../../include/simplepie.inc');
	require_once('simplepie_yahoo_weather_plugin.inc');
	require_once('functions.inc');

$zip = '<INSERT ZIP CODE HERE>';

// Initialize a new SimplePie object.
$feed = new SimplePie();
 
// Parse a Yahoo! Weather feed for San Francisco, CA
$feed->set_feed_url('http://weather.yahooapis.com/forecastrss?p=' . $zip);
 
// We're going to override the built-in SimplePie_Item class with the SimplePie_Item_YWeather class.
$feed->set_item_class('SimplePie_Item_YWeather');
 
// Initialize the feed
$feed->init();
 
// Since Y! Weather feeds only have one item, we'll base everything around that.
$weather = $feed->get_item(0);

$condition = merge_conditions($weather->get_condition());

$folder = str_replace(' ', '', strtolower($condition));

$sunset = format_time($weather->get_sunset());
$sunrise = format_time($weather->get_sunrise());
$time = format_time(get_time());
$timeofday = time_of_day($time, $sunset, $sunrise);

?>
<style>
	<?php echo rand_background($timeofday, $folder); ?>
</style>
<div id="logo"></div>
<?php if ($feed->error): ?>
<p><?php echo $feed->error; ?></p>
<?php endif; ?>
<div id="location"><?php echo $weather->get_city(); ?>, <?php echo $weather->get_state(); ?></div>
<br>
<div id="condition"><?php echo $condition; ?></div>
<br>
<div id="temperature"><?php echo $weather->get_temperature(); ?><?php echo $weather->get_units_temp(); ?>&deg;</div>