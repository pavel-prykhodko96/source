import 'dart:convert';
import 'package:flutter_webrtc/flutter_webrtc.dart';
import 'package:http/http.dart' as http;

// Code in this file was generated with AI and wasn't checked fully

class WebRTCRepository {
  static const String _webRTCServerUrl = 'https://test.webrtc.org/';

  late final MediaStream _localStream;

  Future<void> startStream() async {
    final constraints = <String, dynamic>{'audio': true, 'video': true};
    _localStream = await navigator.mediaDevices.getUserMedia(constraints);
    final videoTracks = _localStream.getVideoTracks();
    if (videoTracks.isEmpty) {
      throw Exception('Failed to get local video stream');
    }
    final videoTrack = videoTracks.first;

    final rtcPeerConnection = await createPeerConnection({
      'iceServers': [
        {'urls': 'stun:stun.l.google.com:19302'},
      ]
    });

    rtcPeerConnection.addTrack(videoTrack, _localStream);

    final offer = await rtcPeerConnection.createOffer();
    await rtcPeerConnection.setLocalDescription(offer);

    final data = {'sdp': offer.sdp, 'type': offer.type};
    final response = await http.post(
      Uri.parse('$_webRTCServerUrl/start'),
      headers: {'Content-Type': 'application/json'},
      body: jsonEncode(data),
    );

    if (response.statusCode != 200) {
      throw Exception('Failed to start WebRTC stream');
    }
  }

  Future<void> stopStream() async {
    _localStream.getTracks().forEach((track) => track.stop());
    final response = await http.get(Uri.parse('$_webRTCServerUrl/stop'));
    if (response.statusCode != 200) {
      throw Exception('Failed to stop WebRTC stream');
    }
  }
}
