import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_bloc.dart';
import 'package:golf_app/constants/golf_routes.dart';
import 'package:golf_app/screens/custom_map/custom_map_screen.dart';
import 'package:golf_app/screens/home/home_screen.dart';
import 'package:golf_app/screens/video_stream/video_stream_screen.dart';

Route generateRoute(RouteSettings settings) {
  return PageRouteBuilder(
    settings: settings,
    transitionsBuilder: (context, animation, secondaryAnimation, child) =>
        child,
    pageBuilder: (context, animation, secondaryAnimation) {
      switch (settings.name) {
        case GolfRoutes.homeScreen:
          return const HomeScreen();
        case GolfRoutes.videoStreamScreen:
          return BlocProvider<WebRTCBloc>(
            create: (_) => WebRTCBloc(),
            child: const VideoStreamScreen(),
          );
        case GolfRoutes.customMapScreen:
          return const CustomMapScreen();
        default:
          return const HomeScreen();
      }
    },
  );
}
