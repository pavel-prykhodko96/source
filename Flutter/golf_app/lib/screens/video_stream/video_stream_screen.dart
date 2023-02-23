import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_bloc.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_event.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_state.dart';
import 'package:golf_app/common/widgets/common_app_bar.dart';
import 'package:golf_app/constants/golf_texts.dart';

class VideoStreamScreen extends StatelessWidget {
  const VideoStreamScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final webRtcBloc = BlocProvider.of<WebRTCBloc>(context);

    return BlocBuilder<WebRTCBloc, WebRTCState>(
      bloc: webRtcBloc,
      builder: (context, state) {
        Widget? player;

        if (state is WebRTCInitialState) {
          player = const Center(
            child: Text(GolfTexts.notStreaming),
          );
        } else if (state is WebRTCStreamingState) {
          // TODO: implement video player here:
        }

        return Scaffold(
          appBar: CommonAppBar(title: const Text(GolfTexts.videoStream)),
          body: player,
          floatingActionButton: FloatingActionButton(
            onPressed: () {
              if (state is WebRTCInitialState) {
                webRtcBloc.add(StartWebRTCStream());
              } else {
                webRtcBloc.add(StopWebRTCStream());
              }
            },
            child: state is WebRTCInitialState
                ? const Icon(Icons.play_arrow)
                : const Icon(Icons.stop),
          ),
        );
      },
    );
  }
}
