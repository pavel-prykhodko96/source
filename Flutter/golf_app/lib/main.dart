import 'package:flutter/material.dart';
import 'package:golf_app/common/get_it.dart';
import 'package:golf_app/constants/golf_routes.dart';
import 'package:golf_app/navigation/navigator.dart';

import 'package:golf_app/navigation/routes_generator.dart' as routes_generator;

void main() {
  setupGetIt();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      initialRoute: GolfRoutes.homeScreen,
      onGenerateRoute: routes_generator.generateRoute,
      navigatorKey: navigator,
    );
  }
}
