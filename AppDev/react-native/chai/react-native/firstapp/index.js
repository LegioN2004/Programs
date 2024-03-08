/**
 * @format
 */

import {AppRegistry} from 'react-native';
// import App from './App'; // this imports the file with name App
import App from './App'; // this imports the file with name AppPro
import AppPro from './AppPro'; // this imports the file with name AppPro
import {name as appName} from './app.json';

AppRegistry.registerComponent(appName, () => AppPro);
