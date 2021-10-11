import 'package:covid_tracker/constants/colors.dart';
import 'package:covid_tracker/homepage.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(COVIDTracker());
}

class COVIDTracker extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        fontFamily: "Circular",
        primaryColor: primaryBlack,
      ),
      home: SafeArea(
        child: HomePage(),
      ),
    );
  }
}

// class COVIDTracker extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return DynamicTheme(
//       data: (brightness) {
//         return ThemeData(
//             primaryColor: primaryBlack,
//             fontFamily: 'Circular',
//             brightness: brightness == Brightness.light
//                 ? Brightness.light
//                 : Brightness.dark,
//             scaffoldBackgroundColor: brightness == Brightness.dark
//                 ? Colors.blueGrey[900]
//                 : Colors.white);
//       },
//       themedWidgetBuilder: (context, theme) {
//         return MaterialApp(
//           debugShowCheckedModeBanner: false,
//           theme: theme,
//           home: HomePage(),
//         );
//       },
//     );
//   }
// }