import 'package:golf_app/common/get_it.dart';
import 'package:golf_app/repositories/web_rtc/webrtc_repository.dart';

class WebRTCService {
  final WebRTCRepository _webRTCRepository;

  WebRTCService({WebRTCRepository? webRTCRepository})
      : _webRTCRepository = webRTCRepository ?? getIt<WebRTCRepository>();

  Future<void> startStream() async {
    try {
      await _webRTCRepository.startStream();
    } catch (e) {
      throw Exception('Failed to start WebRTC stream: $e');
    }
  }

  Future<void> stopStream() async {
    try {
      await _webRTCRepository.stopStream();
    } catch (e) {
      throw Exception('Failed to stop WebRTC stream: $e');
    }
  }
}
