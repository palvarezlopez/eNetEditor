#ifndef NETCONVERTDIALOG_H
#define NETCONVERTDIALOG_H

#include "eNetEditorToolDialog.h"


namespace Ui
{
class netConvertToolDialog;
}

class netConvertToolDialog : public eNetEditorToolDialog
{
    Q_OBJECT

public:

    explicit netConvertToolDialog(eNetEditorMainWindow *neweNetEditorMainW);

    ~netConvertToolDialog();


public slots:

    void openDialog(eNetEditorProject *newProject);

    void resetParameters();

    void updateParameters();


private slots:

    void setInputParameters()
    {

    }

    void setOutputParameters()
    {

    }

    void setProcessingParameters()
    {

    }

    void on_ButtonAccept_released();

    void on_ButtonCancel_released();

    void on_ButtonReset_released();

    void on_ButtonSearchConnectionsFile_released();

    void on_ButtonSearchEdgesfile_released();

    void on_ButtonSearchNodesFile_released();

    void on_ButtonSearchTrafficLightsFile_released();

    void writeNetConvertProcessingMessage();

    void on_TextSumoNetFile_textChanged();

    void on_ButtonSearchSumoNetFile_released();

    void on_TextTypeFile_textChanged();

    void on_ButtonSearchTypeFile_released();

    void on_ButtonSearchHeightmapGeotiffFile_released();

    void on_ButtonSearchHeightmapShapeFile_released();

    void on_ButtonSearchItsumoFile_released();

    void on_ButtonSearchMatsimFile_released();

    void on_ButtonSearchOpenDriveFile_released();

    void on_ButtonSearchOsmFile_released();

    void on_ButtonSearchRobocupDir_released();

    void on_ButtonSearchVissimFile_released();

    void on_ButtonSearchVisumFile_released();

    void on_TextHeightmapGeotiffFile_textChanged();

    void on_TextHeightmapShapeFile_textChanged();

    void on_TextItsumoFile_textChanged();

    void on_TextMatsimFile_textChanged();

    void on_TextOpenDriveFile_textChanged();

    void on_TextOsmFile_textChanged();

    void on_TextRobocupDir_textChanged();

    void on_TextVissimFile_textChanged();

    void on_TextVisumFile_textChanged();


private:

    // UI
    Ui::netConvertToolDialog *ui;

    // netConvert Tool
    netConvertTool *netConvertT;

    // TrafficLight Converter
    trafficLightConverter *tlConverter;

    /** cambiar mayusculas por minusculas **/

    // INPUT PARAMETERS

    // Read SUMO-net from FILE
    QString SumoNetFile;

    // Read XML-node defs from FILE
    QString NodeFiles;

    // Read XML-edge defs from FILE
    QString EdgeFiles;

    // Read XML-connection defs from FILE
    QString ConnectionFiles;

    // Read XML-traffic light defs from FILE
    QString TllogicFiles;

    // Read XML-type defs from FILE
    QString TypeFiles;

    // Read OSM-network from path 'FILE(s)'
    QString OsmFiles;

    // Read OpenDRIVE-network from FILE
    QString OpendriveFiles;

    // Read VISUMNet from FILE
    QString VisumFile;

    // Read VISSIMNet from FILE
    QString VissimFile;

    // Read RoboCupNet from DIR
    QString RobocupDir;

    // Read MATsimNet from FILE
    QString MatsimFiles;

    // Read ITSUMONet from FILE
    QString ItsumoFiles;

    // Read heightmap from ArcGIS shapefile
    QString HeightmapShapefiles;

    // OUTPUT PARAMETERS

    // Read heightmap from GeoTIFF
    QString HeightmapGeotiff;

    // The generated net will be written to FILE
    QString OutputFile;

    // Writes information about joined junctions to FILE (can be loaded as additional nodeFile to reproduce joins
    QString JunctionsJoinOutput;

    // The generated net will be written to FILE using Amitran format
    QString AmitranOutput;

    // The generated net will be written to FILE using MATsim format
    QString MatsimOutput;

    // The generated net will be written to FILE using OpenDRIVE format
    QString OpendriveOutput;

    // The generated net will be written to dlrNavteq files with the given PREFIX
    QString DlrNavteqOutput;

    // Street names will be included in the output (if available); default: false
    bool OutputStreetNames;

    // Writes original names, if given, as parameter; default: false
    bool OutputOriginalNames;

    // Writes street signs as POIs to FILE
    QString StreetSignOutput;


    // PROCESSING PARAMETERS

    // Uses a simple method for projection; default: false
    bool SimpleProjection;

    // Number of places to shift decimal point to right in geoCoordinates; default: 0
    int ProjScale;

    // Determine the UTM zone (for a universal transversal mercator projection based on the WGS84 ellipsoid); default: false
    bool ProjUtm;

    // Determine the DHDN zone (for a transversal mercator projection based on the bessel ellipsoid, "GaussKrueger"); default: false
    bool ProjDhdn;

    // Uses STR as proj.4 definition for projection; default: !
    QString Proj;

    // Inverses projection; default: false
    bool ProjInverse;

    // Convert from GaussKrueger to UTM; default: false
    bool ProjDhdnutm;

    // Write geo coordinates in plain-xml; default: false
    bool ProjPlainGeo;

    // Does not instatiate traffic lights loaded from other formats than XML; default: false
    bool TlsDiscardLoaded;

    // Does not instatiate traffic lights at geometryLike nodes loaded from other formats than XML; default: false
    bool TlsDiscardSimple;

    // Interprets STR as list of junctions to be controlled by TLS
    QString TlsSet;

    //Interprets STR as list of junctions to be not controlled by TLS
    QString TlsUnset;

    // Turns on TLS guessing; default: false
    bool TlsGuess;

    // Sets district nodes as tlsControlled; default: false
    bool TlsTazNodes;

    // Includes node clusters into guess; default: false
    bool TlsGuessJoining;

    // Tries to cluster tlsControlled nodes; default: false
    bool TlsJoin;

    // Use INT as green phase duration; default: 31
    int TlsGreenTime;

    // Defines smallest vehicle deceleration; default: 3
    qreal TlsYellowMinDecel;

    // Given yellow times are patched even if being too short; default: false
    bool TlsYellowPatchSmall;

    // Set INT as fixed time for yellow phase durations
    int TlsYellowTime;

    // TLSs in STR will be shifted by halfPhase
    QString TlsHalfOffset;

    // TLSs in STR will be shifted by quarterPhase
    QString TlsQuarterOffset;

    // TLSs with unspecified type will use STR as their algorithm; default: static
    QString TlsDefaultType;

    // Enable rampGuessing; default: false
    bool RampsGuess;

    // Treat edges with speed > FLOAT as no ramps; default: -1
    qreal RampsMaxRampSpeed;

    // Treat edges with speed < FLOAT as no highways; default: 21.9444
    qreal RampsMinHighwaySpeed;

    // Use FLOAT as rampLength; default: 100
    qreal RampsRampLength;

    // Tries to handle the given edges as ramps
    QString RampsSet;

    // Avoids edge splitting; default: false
    bool RampsNoSplit;

    // Only keep edges with speed in meters/second > FLOAT
    qreal KeepEdgesMinSpeed;

    // Remove edges in STR
    QString RemoveEdgesExplicit;

    // Only keep edges in STR
    QString KeepEdgesExplicit;

    // Only keep edges in FILE
    QString KeepEdgesInputFile;

    // Remove edges after joining; default: false
    bool KeepEdgesPostload;

    // Only keep edges which are located within the given boundary (given either as CARTESIAN corner coordinates <xmin,ymin,xmax,ymax> or as polygon <x0,y0,x1,y1,...>)
    QString KeepEdgesInBoundary;

    // Only keep edges which are located within the given boundary (given either as GEODETIC corner coordinates <lon-min,lat-min,lon-max,lat-max> or as polygon <lon0,lat0,lon1,lat1,...>)
    QString KeepEdgesInGeoBoundary;

    // Only keep edges which allow one of the vclasss in STR
    QString KeepEdgesByVclass;

    // Remove edges which allow only vclasses from STR
    QString RemoveEdgesByVclass;

    // Only keep edges where type is in STR
    QString KeepEdgesByType;

    // Remove edges where type is in STR
    QString RemoveEdgesByType;

    // Removes isolated edges; default: false
    bool RemoveEdgesIsolated;

    // All nodes will be unregulated; default: false
    bool KeepNodesUnregulated;

    // Do not regulate nodes in STR
    QString KeepNodesUnregulatedExplicit;

    // Do not regulate district nodes; default: false
    bool KeepNodesUnregulatedDistrictNodes;

    // Continue on broken input; default: false
    bool IgnoreErrors;

    // Continue on invalid connections; default: false
    bool IgnoreErrorsConnections;

    // Show errors in connections at parsing; default: false
    bool ShowErrorsConnectionsFirstTry;

    // Continue on unknown edge types; default: false
    bool IgnoreErrorsEdgeType;

    // The factor for flow to no. lanes conversion; default: 1800
    qreal LanesFromCapacityNorm;

    // vmax is parsed as given in km/h (some); default: false
    bool SpeedInKmh;

    // If edge shapes do not end at the node positions, extend them; default: false
    bool PlainExtendEdgeShape;

    // The edge lengths given in the MATSIMFile will be kept; default: false
    bool MatsimKeepLength;

    // The lane number will be computed from the capacity; default: false
    bool MatsimLanesFromCapacity;

    // Read edge ids from column STR
    QString ShapefileStreetId;

    // Read fromNode ids from column STR
    QString ShapefileFromId;

    // Read toNode ids from column STR
    QString ShapefileToId;

    // Read type ids from column STR
    QString ShapefileTypeId;

    // Uses edge type defaults on problems; default: false
    bool ShapefileUseDefaultsOnFailure;

    // Insert edges in both directions; default: false
    bool ShapefileAllBidirectional;

    // Guess the proper projection; default: false
    bool ShapefileGuessProjection;

    // Structure join offset; default: 5
    qreal VissimJoinDistance;

    // Use FLOAT as default speed; default: 50
    qreal VissimDefaultSpeed;

    // Factor for edge velocity; default: 1
    qreal VissimSpeedNorm;

    //	Writes lanes without an explicit speed set; default: false
    bool VissimReportUnsetSpeeds;

    // Uses priorities from types; default: false
    bool VisumUseTypePriority;

    // Uses lane numbers from types; default: false
    bool VisumUseTypeLaneno;

    // Uses speeds from types; default: false
    bool VisumUseTypeSpeed;

    // Sets connector speed; default: 100
    qreal VisumConnectorSpeeds;

    // Sets connector lane number; default: 3
    int VisumConnectorsLaneNumber;

    // Excludes connectors; default: false
    bool VisumNoConnectors;

    // Computes the number of lanes from the edges' capacities; default: false
    bool VisumRecomputeLaneNumber;

    // Prints all warnings, some of which are due to VISUM misbehaviour; default: false
    bool VisumVerboseWarnings;

    // Skips the check for duplicate nodes and edges; default: false
    bool OsmSkipDuplicatesCheck;

    // Imports railway edges as oneWay by default; default: true
    bool OsmRailwayOnewayDefault;

    // Imports elevation data; default: false
    bool OsmElevation;

    // Imports all lane types; default: false
    bool OpendriveImportAllLanes;

    // Whether lane widths shall be ignored.; default: false
    bool OpendriveIgnoreWidths;

    // Omits internal links; default: false
    bool NoInternalLinks;

    // Removes vehicle class restrictions from imported edges; default: false
    bool DismissVclasses;

    // Disables building turnarounds; default: false
    bool NoTurnarounds;

    // Disables building turnarounds at tlsControlled junctions; default: false
    bool NoTurnaroundsTls;

    // Disables building connections to left; default: false
    bool NoLeftConnections;

    // Splits edges across geometry nodes; default: false
    bool GeometrySplit;

    // Replace nodes which only define edge geometry by geometry points (joins edges); default: false
    bool GeometryRemove;

    // splits geometry to restrict segment length; default: 0
    qreal GeometryMaxSegmentLength;

    // reduces too similar geometry points
    qreal GeometryMinDist;

    // Warn about edge geometries with an angle above DEGREES in successive segments; default: 99
    qreal GeometryMaxAngle;

    // Warn about edge geometries with a turning radius less than METERS at the start or end; default: 9
    qreal GeometryMinRadius;

    // Straighten edge geometries to avoid turning radii less than geometryMinRadius; default: false
    bool GeometryMinRadiusFix;

    // Warn if the junction shape is to far away from the original node position; default: 20
    qreal GeometryJunctionMismatchThreshold;

    // Turn off normalizing node positions; default: false
    bool OffsetDisableNormalization;

    // Adds FLOAT to net xPositions; default: 0
    qreal OffsetX;

    // Adds FLOAT to net yPositions; default: 0
    qreal OffsetY;

    // Flips the yCoordinate along zero; default: false
    bool FlipYAxis;

    // Enable roundaboutGuessing; default: false
    bool RoundaboutsGuess;

    // Assumes left-hand traffic on the network; default: false
    bool Lefthand;

    // Joins junctions that are close to each other (recommended for OSM import); default: false
    bool JunctionsJoin;

    // Determines the maximal distance for joining junctions (defaults to 10); default: 10
    qreal JunctionsJoinDist;

    // Interprets STR as list of junctions to exclude from joining
    QString JunctionsJoinExclude;

    // Modifies all edge speeds by adding FLOAT; default: 0
    qreal SpeedOffset;

    // Modifies all edge speeds by multiplying by FLOAT; default: 1
    qreal SpeedFactor;

    // Generate INT intermediate points to smooth out intersection corners; default: 0
    int JunctionsCornerDetail;

    // Allow driving onto a multiLane road if there are foes on other lanes (at roundabouts); default: true
    bool CheckLaneFoesRoundabout;

    // Allow driving onto a multiLane road if there are foes on other lanes (everywhere); default: false
    bool CheckLaneFoesAll;

    // Guess pedestrian sidewalks based on edge speed; default: false
    bool SidewalksGuess;

    // Add sidewalks for edges with a speed equal or below the given limit; default: 13.89
    qreal SidewalksGuessMaxSpeed;

    // Add sidewalks for edges with a speed above the given limit; default: 5.8
    qreal SidewalksGuessMinSpeed;

    // Add sidewalks for edges that allow pedestrians on any of their lanes regardless of speed; default: false
    bool SidewalksGuessFromPermissions;

    // Guess pedestrian crossings based on the presence of sidewalks; default: false
    bool CrossingsGuess;

    // Determines the maximal distance for joining traffic lights (defaults to 20); default: 20
    qreal TlsJoinDist;

    // Interprets tls nodes surrounding an intersection as signal positions for a larger TLS. This is typical pattern for OSMDerived networks; default: false
    bool TlsGuessSignals;

    // Distance for interpreting nodes as signal locations; default: 25
    qreal TlsGuessSignalsDist;

    // The default number of lanes in an edge; default: 1
    int DefaultLanenumber;

    // The default speed on an edge (in m/s); default: 13.9
    qreal DefaultSpeed;

    // The default priority of an edge; default: -1
    int DefaultPriority;

    // The default width of added sidewalks; default: 2
    qreal DefaultSidewalkWidth;

    // Switches to verbose output; default: false
    bool Verbose;

    // Prints option values before processing; default: false
    bool PrintOptions;

    // Prints this screen; default: false
    bool Help;

    // Prints the current version; default: false
    bool Version;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString xmlValidation;

    // Disables output of warnings; default: false
    bool NoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString Log;

    // Writes all nonError messages to FILE (implies verbose)
    QString MessageLog;

    // Writes all warnings and errors to FILE
    QString ErrorLog;

    // Initialises the random number generator with the current system time; default: false
    bool Random;

    //Initialises the random number generator with the given value; default: 23423
    int Seed;
};

#endif // NETCONVERT_H
