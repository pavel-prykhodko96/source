import 'package:get_it/get_it.dart';
import 'package:golf_app/repositories/web_rtc/webrtc_repository.dart';
import 'package:golf_app/services/webrtc_service.dart';

GetIt getIt = GetIt.instance;

Future<void> setupGetIt() async {
  getIt.registerLazySingleton<WebRTCRepository>(() => WebRTCRepository());
  getIt.registerLazySingleton<WebRTCService>(() => WebRTCService());
}
