import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_event.dart';
import 'package:golf_app/blocs/web_rtc/web_rtc_state.dart';
import 'package:golf_app/common/get_it.dart';
import 'package:golf_app/services/webrtc_service.dart';

class WebRTCBloc extends Bloc<WebRTCEvent, WebRTCState> {
  final WebRTCService _webRtcService;

  WebRTCBloc({WebRTCService? webRtcService})
      : _webRtcService = webRtcService ?? getIt<WebRTCService>(),
        super(WebRTCInitialState()) {
    on<StartWebRTCStream>((event, emit) async {
      emit(WebRTCStreamingState());
      try {
        await _webRtcService.startStream();
      } catch (e) {
        // Handle any errors here
      }
    });
    on<StopWebRTCStream>((event, emit) async {
      emit(WebRTCInitialState());
      try {
        await _webRtcService.stopStream();
      } catch (e) {
        // Handle any errors here
      }
    });
  }
}
