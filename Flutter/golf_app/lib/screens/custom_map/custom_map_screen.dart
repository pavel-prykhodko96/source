import 'package:flutter/material.dart';
import 'package:golf_app/common/widgets/common_app_bar.dart';
import 'package:golf_app/constants/golf_texts.dart';

class CustomMapScreen extends StatelessWidget {
  const CustomMapScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: CommonAppBar(title: const Text(GolfTexts.customMap)),
      body: const Center(
        child: Text(GolfTexts.customMap),
      ),
    );
  }
}
