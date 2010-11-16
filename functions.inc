<?php
	function get_time()
	{
	// Prints something like: Monday 8th of August 2005 03:12:46 PM
		return date('g:i A');
	}

	function format_time($inputtime)
	{
		$inputtime = str_replace(' ', '', strtolower($inputtime));
		$time = explode(':', $inputtime);
		$hour = $time[0];
		$minute = $time[1];
		if (strpos($minute, 'am'))
		{
			str_replace('am', '', $minute);
		}
		if (strpos($minute, 'pm'))
		{
			str_replace('pm', '', $minute);
			if ($hour < 12) $hour = $hour + 12;
		}
		$time[2] = $hour . $minute;
		$time[2] = str_replace('am', '', $time[2]);
		$time[2] = str_replace('pm', '', $time[2]);
		return $time;
	}
	
	function merge_conditions($condition)
	{
		if($condition=='Partly Cloudy') $condition = 'Fair';
		if($condition=='Windy') $condition = 'Fair';
		if($condition=='Blustery') $condition = 'Fair';
		if($condition=='Light Rain') $condition = 'Fair';

		if($condition=='Mostly Cloudy') $condition = 'Cloudy';

		if($condition=='Scattered Showers') $condition = 'Rain';
		if($condition=='Hail') $condition = 'Rain';
		if($condition=='Showers') $condition = 'Rain';
		if($condition=='Drizzle') $condition = 'Rain';
		if($condition=='Freezing Rain') $condition = 'Rain';
		if($condition=='Freezing Drizzle') $condition = 'Rain';

		if($condition=='Thundershowers') $condition = 'Thunderstorms';
		if($condition=='Severe Thunderstorms') $condition = 'Thunderstorms';
		if($condition=='Scattered Thunderstorms') $condition = 'Thunderstorms';
		if($condition=='Isolated Thunderstorms') $condition = 'Thunderstorms';
		if($condition=='Isolated Thundershowers') $condition = 'Thunderstorms';
		
		return $condition;
	}
	
	function file_count($directory)
	{
		$count = count(glob($directory . "*"));
		return $count;
	}
	
	function time_of_day($currenttime, $sunset, $sunrise)
	{
		if ($currenttime[2] > $sunrise[2] && $currenttime[2] < $sunset[2]) $timeofday = 'day';
		else $timeofday = 'night';
		return $timeofday;
	}
	
	function rand_background($timeofday, $folder)
	{
		$imagepath = 'img/conditions/' . $timeofday . '/' . $folder . '/';
		$randimage = rand(1,file_count($imagepath));
		$css = 'body { background: url(' . $imagepath . $randimage . '.jpg) no-repeat top center; }';
		return $css;
	}
?>