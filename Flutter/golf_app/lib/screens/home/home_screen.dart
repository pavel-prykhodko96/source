import 'package:flutter/material.dart';
import 'package:golf_app/common/widgets/common_app_bar.dart';
import 'package:golf_app/constants/golf_routes.dart';
import 'package:golf_app/constants/golf_texts.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: CommonAppBar(title: const Text(GolfTexts.homeScreen)),
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              TextButton(
                onPressed: () => Navigator.of(context)
                    .pushNamed(GolfRoutes.videoStreamScreen),
                child: const Text("To Video Stream"),
              ),
              TextButton(
                onPressed: () =>
                    Navigator.of(context).pushNamed(GolfRoutes.customMapScreen),
                child: const Text("To Custom Map with Real-time Location"),
              ),
            ],
          ),
        ));
  }
}
