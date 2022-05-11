// swift-tools-version: 5.6

import PackageDescription

let package = Package(
    name: "c4w-wifi-sdk",
    platforms: [
        .iOS(.v11)
    ],
    products: [
        .library(
            name: "Cloud4WiSDKWiFi",
            targets: ["Cloud4WiSDKWiFi"]),
    ],
    targets: [
        .binaryTarget(
            name: "Cloud4WiSDKWiFi",
            path: "Cloud4WiSDKWiFi.xcframework")
    ]
)
