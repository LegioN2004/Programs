import { Stack, useRouter } from 'expo-router';
import { useState } from 'react';
import { SafeAreaView, ScrollView, View } from 'react-native';

import {
	NearbyJobs,
	PopularJobs,
	ScreenHeaderBtn,
	Welcome,
} from '../components';
import { COLORS, SIZES, icons, images } from '../constants';

export const Home = () => {
	const router = useRouter();

	return (
		<SafeAreaView style={{ flex: 1, backgroundColor: COLORS.lightWhite }}>
			<Text>Home Screen</Text>
			<Stack.screen>
				options=
				{{
					headerStyle: { backgroundColor: COLORS.lightWhite },
				}}
			</Stack.screen>
		</SafeAreaView>
	);
};
