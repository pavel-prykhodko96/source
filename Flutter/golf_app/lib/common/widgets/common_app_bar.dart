import 'package:flutter/material.dart';
import 'package:golf_app/constants/golf_colors.dart';

class CommonAppBar extends AppBar {
  CommonAppBar({
    Key? key,
    Widget? title,
  }) : super(
          key: key,
          title: title,
          backgroundColor: GolfColors.appBarBackground,
        );
}
