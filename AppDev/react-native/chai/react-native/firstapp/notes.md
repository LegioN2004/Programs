# Chai aur Code

## All about the files and file structure

- Tests folder contains all the test files required for testing the application and here all the testers are going to work through

- _All the files are gonna be in the typescript lang_
- bundle: contains the config files and we don't need to touch those
- Two major folders: Since we write the code once in the react-native world in the app.jsx or app.tsx file, then the code is being moved to the two folders android and ios to keep their respective platoform specific code in it.
  - In android: May not need to come most of the time but there may be a need to come here
    - build.gradle file: to check the dependencies, build, dependencies, etc especially to check what min sdk version you are supporting and what is the targeted sdk version. Or to add some dependencies
    - local.properties: to setup the sdk.dir
    - Rest of the java files are generated automatically and we never need to touch those.
  - In ios: May not need to come most of the time but there may be a need to come here
    - You only need to come here for the pod file which is an ios specific file to setup dependencies, all of new packages, etc and it is important
- node_modules: it consists of all the node files that we need to run everything in the react-native app
- .gitignore: for removing unnecessary files to not track in version control
- prettier.js: file to formatting properly the jsx or tsx files
- ruby-version: for versioning ruby specifically required for ios
- watchman: constantly reloads your application when we update something in the files, just like hot reload live-server. Not being used now but can be used later
- app.json: One of the major configuration file in the json format, from where the android and ios takes the name of the app
- App.tsx: It is the main file, where we code stuff and where we make the whole app. We only care about this file
- babel-config.js: babel configuration, it is a bundler that combines all the files into one available everyone that makes sense, since JS doesn't know how the files are splitted and how these files are running the app in a physical devices. And metro is one bundler used in react-native to run this.
- gem file: ruby file no need to touch
- index.js: the react-native doesn't know which file to run, the metro builder runs this index.js file, and then it'll run the stuff in that file
- package.json: This file consists the things required to install and the dependencies, scripts, etc.
