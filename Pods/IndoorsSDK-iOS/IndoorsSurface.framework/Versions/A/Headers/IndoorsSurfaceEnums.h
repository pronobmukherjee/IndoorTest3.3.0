#ifndef IndoorsSurface_IndoorsSurfaceEnums_h
#define IndoorsSurface_IndoorsSurfaceEnums_h

typedef enum {
    IndoorsSurfaceZoneDisplayModeUserCurrentLocation, // Only display user's current zone.
    IndoorsSurfaceZoneDisplayModeAllAvailable, // Display all zones.
    IndoorsSurfaceZoneDisplayModeNone // Not display any zone.
} IndoorsSurfaceZoneDisplayModes;

typedef enum {
    IndoorsSurfaceUserPositionDisplayModeDefault,
    IndoorsSurfaceUserPositionDisplayModeCustom,
    IndoorsSurfaceUserPositionDisplayModeNone
} IndoorsSurfaceUserPositionDisplayModes;

#endif
