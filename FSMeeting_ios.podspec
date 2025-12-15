#
# Be sure to run `pod lib lint FSMeeting_ios.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'FSMeeting_ios'
  s.version          = '3.36.10.43'
  s.summary          = 'A short description of FSMeeting_ios.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/paas-hst/FSMeeting_ios'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'hst' => 'paas@hst.com' }
  s.source           = { :git => 'https://github.com/paas-hst/FSMeeting_ios.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '11.0'

  # s.source_files = 'FSMeeting_ios/Classes/**/*'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64' }
  s.vendored_frameworks = 'FSMeeting_ios/Framework/FSMeeting.framework', 'FSMeeting_ios/Framework/IosSdk.framework'
  
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # s.resource_bundles = {
  #   'FSMeeting_ios' => ['FSMeeting_ios/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
