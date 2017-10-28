#ifndef NETCONVERTTOOLCONFIGURATION_H
#define NETCONVERTTOOLCONFIGURATION_H

#include "eNetEditorToolConfiguration.h"


class netConvertToolConfiguration : public eNetEditorToolConfiguration
{
public:

    netConvertToolConfiguration();

    ~netConvertToolConfiguration();

    // GET FUNCTIONS

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultSumoNetFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultNodeFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultEdgeFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultConnectionFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTllogicFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTypeFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultShapefilePrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultDlrNavteqPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultOsmFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultOpendriveFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultVisumFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultVissimFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultRobocupDir() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultMatsimFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultItsumoFiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultHeightmapShapefiles() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultHeightmapGeotiff() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultOutputFile() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultPlainOutputPrefix() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultJunctionsJoinOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultAmitranOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultMatsimOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultOpendriveOutput() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultDlrNavteqOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOutputStreetNames() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOutputOriginalNames() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultStreetSignOutput() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultSimpleProjection() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultProjScale() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultProjUtm() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultProjDhdn() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultProj() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultProjInverse() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultProjDhdnutm() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultProjPlainGeo() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsDiscardLoaded() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsDiscardSimple() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTlsSet() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTlsUnset() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsGuess() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsTazNodes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsGuessJoining() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsJoin() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultTlsGreenTime() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultTlsYellowMinDecel() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsYellowPatchSmall() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultTlsYellowTime() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTlsHalfOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTlsQuarterOffset() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultTlsDefaultType() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultRampsGuess() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultRampsMaxRampSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultRampsMinHighwaySpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultRampsRampLength() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultRampsSet() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultRampsNoSplit() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultKeepEdgesMinSpeed() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultRemoveEdgesExplicit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesExplicit() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesInputFile() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultKeepEdgesPostload() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesInBoundary() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesInGeoBoundary() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesByVclass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultRemoveEdgesByVclass() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepEdgesByType() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultRemoveEdgesByType() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultRemoveEdgesIsolated() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultKeepNodesUnregulated() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultKeepNodesUnregulatedExplicit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultKeepNodesUnregulatedDistrictNodes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultIgnoreErrors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultIgnoreErrorsConnections() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultShowErrorsConnectionsFirstTry() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultIgnoreErrorsEdgeType() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultLanesFromCapacityNorm() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultSpeedInKmh() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultPlainExtendEdgeShape() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultMatsimKeepLength() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultMatsimLanesFromCapacity() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultShapefileStreetId() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultShapefileFromId() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultShapefileToId() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultShapefileTypeId() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultShapefileUseDefaultsOnFailure() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultShapefileAllBidirectional() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultShapefileGuessProjection() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultVissimJoinDistance() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultVissimDefaultSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultVissimSpeedNorm() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVissimReportUnsetSpeeds() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumUseTypePriority() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumUseTypeLaneno() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumUseTypeSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultVisumConnectorSpeeds() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultVisumConnectorsLaneNumber() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumNoConnectors() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumRecomputeLaneNumber() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVisumVerboseWarnings() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOsmSkipDuplicatesCheck() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOsmRailwayOnewayDefault() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOsmElevation() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOpendriveImportAllLanes() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOpendriveIgnoreWidths() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultNoInternalLinks() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultDismissVclasses() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultNoTurnarounds() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultNoTurnaroundsTls() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultNoLeftConnections() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultGeometrySplit() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultGeometryRemove() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultGeometryMaxSegmentLength() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultGeometryMinDist() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultGeometryMaxAngle() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultGeometryMinRadius() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultGeometryMinRadiusFix() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultGeometryJunctionMismatchThreshold() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultOffsetDisableNormalization() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultOffsetX() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultOffsetY() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultFlipYAxis() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultRoundaboutsGuess() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultLefthand() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultJunctionsJoin() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultJunctionsJoinDist() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultJunctionsJoinExclude() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultSpeedOffset() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultSpeedFactor() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultJunctionsCornerDetail() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultCheckLaneFoesRoundabout() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultCheckLaneFoesAll() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultSidewalksGuess() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultSidewalksGuessMaxSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultSidewalksGuessMinSpeed() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultSidewalksGuessFromPermissions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultCrossingsGuess() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultTlsJoinDist() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultTlsGuessSignals() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultTlsGuessSignalsDist() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultDefaultLanenumber() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultDefaultSpeed() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultDefaultPriority() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    qreal getNetConvertDefaultDefaultSidewalkWidth() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVerbose() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultPrintOptions() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultHelp() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultVersion() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultxmlValidation() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultNoWarnings() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultMessageLog() const;

    /**
        @brief Get

        @return QString with the
        @details Get
    */
    const QString &getNetConvertDefaultErrorLog() const;

    /**
        @brief Get
        @return true if X is enabled, false in other case
        @details Get
    */
    bool getNetConvertDefaultRandom() const;

    /**
        @brief Get
        @return qreal with the
        @details Get
    */
    int getNetConvertDefaultSeed() const;


    // SET FUNCTIONS

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSumoNetFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNodeFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultEdgeFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultConnectionFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTllogicFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTypeFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefilePrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDlrNavteqPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOsmFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOpendriveFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVissimFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRobocupDir(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultMatsimFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultItsumoFiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultHeightmapShapefiles(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultHeightmapGeotiff(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOutputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultPlainOutputPrefix(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultJunctionsJoinOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultAmitranOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultMatsimOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOpendriveOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDlrNavteqOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOutputStreetNames(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOutputOriginalNames(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultStreetSignOutput(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSimpleProjection(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjScale(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjUtm(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjDhdn(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProj(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjInverse(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjDhdnutm(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultProjPlainGeo(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsDiscardLoaded(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsDiscardSimple(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsSet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsUnset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsTazNodes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsGuessJoining(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsJoin(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsGreenTime(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsYellowMinDecel(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsYellowPatchSmall(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsYellowTime(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsHalfOffset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsQuarterOffset(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsDefaultType(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsMaxRampSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsMinHighwaySpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsRampLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsSet(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRampsNoSplit(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesMinSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRemoveEdgesExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesInputFile(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesPostload(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesInBoundary(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesInGeoBoundary(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesByVclass(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRemoveEdgesByVclass(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepEdgesByType(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRemoveEdgesByType(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRemoveEdgesIsolated(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepNodesUnregulated(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepNodesUnregulatedExplicit(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultKeepNodesUnregulatedDistrictNodes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultIgnoreErrors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultIgnoreErrorsConnections(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShowErrorsConnectionsFirstTry(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultIgnoreErrorsEdgeType(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultLanesFromCapacityNorm(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSpeedInKmh(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultPlainExtendEdgeShape(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultMatsimKeepLength(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultMatsimLanesFromCapacity(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileStreetId(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileFromId(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileToId(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileTypeId(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileUseDefaultsOnFailure(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileAllBidirectional(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultShapefileGuessProjection(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVissimJoinDistance(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVissimDefaultSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVissimSpeedNorm(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVissimReportUnsetSpeeds(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumUseTypePriority(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumUseTypeLaneno(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumUseTypeSpeed(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumConnectorSpeeds(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumConnectorsLaneNumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumNoConnectors(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumRecomputeLaneNumber(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVisumVerboseWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOsmSkipDuplicatesCheck(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOsmRailwayOnewayDefault(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOsmElevation(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOpendriveImportAllLanes(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOpendriveIgnoreWidths(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNoInternalLinks(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDismissVclasses(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNoTurnarounds(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNoTurnaroundsTls(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNoLeftConnections(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometrySplit(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryRemove(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryMaxSegmentLength(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryMinDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryMaxAngle(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryMinRadius(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryMinRadiusFix(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultGeometryJunctionMismatchThreshold(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOffsetDisableNormalization(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOffsetX(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultOffsetY(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultFlipYAxis(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRoundaboutsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultLefthand(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultJunctionsJoin(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultJunctionsJoinDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultJunctionsJoinExclude(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSpeedOffset(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSpeedFactor(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultJunctionsCornerDetail(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultCheckLaneFoesRoundabout(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultCheckLaneFoesAll(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSidewalksGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSidewalksGuessMaxSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSidewalksGuessMinSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSidewalksGuessFromPermissions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultCrossingsGuess(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsJoinDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsGuessSignals(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultTlsGuessSignalsDist(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDefaultLanenumber(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDefaultSpeed(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDefaultPriority(int value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultDefaultSidewalkWidth(qreal value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVerbose(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultPrintOptions(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultHelp(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultVersion(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultxmlValidation(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultNoWarnings(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultMessageLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultErrorLog(const QString &value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultRandom(bool value);

    /**
        @brief Set
        @param
        @details set
    */
    void setNetConvertDefaultSeed(int value);


private:

    // Read SUMO-net from FILE
    QString netConvertDefaultSumoNetFile;

    // Read XML-node defs from FILE
    QString netConvertDefaultNodeFiles;

    // Read XML-edge defs from FILE
    QString netConvertDefaultEdgeFiles;

    // Read XML-connection defs from FILE
    QString netConvertDefaultConnectionFiles;

    // Read XML-traffic light defs from FILE
    QString netConvertDefaultTllogicFiles;

    // Read XML-type defs from FILE
    QString netConvertDefaultTypeFiles;

    // Read shapefiles (ArcView, Tiger, ...) from files starting with 'FILE'
    QString netConvertDefaultShapefilePrefix;

    // Read converted Navteq GDF data (unsplitted Elmar-network) from path 'FILE'
    QString netConvertDefaultDlrNavteqPrefix;

    // Read OSM-network from path 'FILE(s)'
    QString netConvertDefaultOsmFiles;

    // Read OpenDRIVE-network from FILE
    QString netConvertDefaultOpendriveFiles;

    // Read VISUMNet from FILE
    QString netConvertDefaultVisumFile;

    // Read VISSIMNet from FILE
    QString netConvertDefaultVissimFile;

    // Read RoboCupNet from DIR
    QString netConvertDefaultRobocupDir;

    // Read MATsimNet from FILE
    QString netConvertDefaultMatsimFiles;

    // Read ITSUMONet from FILE
    QString netConvertDefaultItsumoFiles;

    // Read heightmap from ArcGIS shapefile
    QString netConvertDefaultHeightmapShapefiles;

    // Read heightmap from GeoTIFF
    QString netConvertDefaultHeightmapGeotiff;

    // Prefix which is applied to all output files. The special string 'TIME' is replaced by the current time.
    QString netConvertDefaultOutputPrefix;

    // The generated net will be written to FILE
    QString netConvertDefaultOutputFile;

    // Prefix of files to write plain xml nodes, edges and connections to
    QString netConvertDefaultPlainOutputPrefix;

    // Writes information about joined junctions to FILE (can be loaded as additional nodeFile to reproduce joins
    QString netConvertDefaultJunctionsJoinOutput;

    // The generated net will be written to FILE using Amitran format
    QString netConvertDefaultAmitranOutput;

    // The generated net will be written to FILE using MATsim format
    QString netConvertDefaultMatsimOutput;

    // The generated net will be written to FILE using OpenDRIVE format
    QString netConvertDefaultOpendriveOutput;

    // The generated net will be written to dlrNavteq files with the given PREFIX
    QString netConvertDefaultDlrNavteqOutput;

    // Street names will be included in the output (if available); default: false
    bool netConvertDefaultOutputStreetNames;

    // Writes original names, if given, as parameter; default: false
    bool netConvertDefaultOutputOriginalNames;

    // Writes street signs as POIs to FILE
    QString netConvertDefaultStreetSignOutput;

    // Uses a simple method for projection; default: false
    bool netConvertDefaultSimpleProjection;

    // Number of places to shift decimal point to right in geoCoordinates; default: 0
    int netConvertDefaultProjScale;

    // Determine the UTM zone (for a universal transversal mercator projection based on the WGS84 ellipsoid); default: false
    bool netConvertDefaultProjUtm;

    // Determine the DHDN zone (for a transversal mercator projection based on the bessel ellipsoid, "GaussKrueger"); default: false
    bool netConvertDefaultProjDhdn;

    // Uses STR as proj.4 definition for projection; default: !
    QString netConvertDefaultProj;

    // Inverses projection; default: false
    bool netConvertDefaultProjInverse;

    // Convert from GaussKrueger to UTM; default: false
    bool netConvertDefaultProjDhdnutm;

    // Write geo coordinates in plain-xml; default: false
    bool netConvertDefaultProjPlainGeo;

    // Does not instatiate traffic lights loaded from other formats than XML; default: false
    bool netConvertDefaultTlsDiscardLoaded;

    // Does not instatiate traffic lights at geometryLike nodes loaded from other formats than XML; default: false
    bool netConvertDefaultTlsDiscardSimple;

    // Interprets STR as list of junctions to be controlled by TLS
    QString netConvertDefaultTlsSet;

    //Interprets STR as list of junctions to be not controlled by TLS
    QString netConvertDefaultTlsUnset;

    // Turns on TLS guessing; default: false
    bool netConvertDefaultTlsGuess;

    // Sets district nodes as tlsControlled; default: false
    bool netConvertDefaultTlsTazNodes;

    // Includes node clusters into guess; default: false
    bool netConvertDefaultTlsGuessJoining;

    // Tries to cluster tlsControlled nodes; default: false
    bool netConvertDefaultTlsJoin;

    // Use INT as green phase duration; default: 31
    int netConvertDefaultTlsGreenTime;

    // Defines smallest vehicle deceleration; default: 3
    qreal netConvertDefaultTlsYellowMinDecel;

    // Given yellow times are patched even if being too short; default: false
    bool netConvertDefaultTlsYellowPatchSmall;

    // Set INT as fixed time for yellow phase durations
    int netConvertDefaultTlsYellowTime;

    // TLSs in STR will be shifted by halfPhase
    QString netConvertDefaultTlsHalfOffset;

    // TLSs in STR will be shifted by quarterPhase
    QString netConvertDefaultTlsQuarterOffset;

    // TLSs with unspecified type will use STR as their algorithm; default: static
    QString netConvertDefaultTlsDefaultType;

    // Enable rampGuessing; default: false
    bool netConvertDefaultRampsGuess;

    // Treat edges with speed > FLOAT as no ramps; default: -1
    qreal netConvertDefaultRampsMaxRampSpeed;

    // Treat edges with speed < FLOAT as no highways; default: 21.9444
    qreal netConvertDefaultRampsMinHighwaySpeed;

    // Use FLOAT as rampLength; default: 100
    qreal netConvertDefaultRampsRampLength;

    // Tries to handle the given edges as ramps
    QString netConvertDefaultRampsSet;

    // Avoids edge splitting; default: false
    bool netConvertDefaultRampsNoSplit;

    // Only keep edges with speed in meters/second > FLOAT
    qreal netConvertDefaultKeepEdgesMinSpeed;

    // Remove edges in STR
    QString netConvertDefaultRemoveEdgesExplicit;

    // Only keep edges in STR
    QString netConvertDefaultKeepEdgesExplicit;

    // Only keep edges in FILE
    QString netConvertDefaultKeepEdgesInputFile;

    // Remove edges after joining; default: false
    bool netConvertDefaultKeepEdgesPostload;

    // Only keep edges which are located within the given boundary (given either as CARTESIAN corner coordinates <xmin,ymin,xmax,ymax> or as polygon <x0,y0,x1,y1,...>)
    QString netConvertDefaultKeepEdgesInBoundary;

    // Only keep edges which are located within the given boundary (given either as GEODETIC corner coordinates <lon-min,lat-min,lon-max,lat-max> or as polygon <lon0,lat0,lon1,lat1,...>)
    QString netConvertDefaultKeepEdgesInGeoBoundary;

    // Only keep edges which allow one of the vclasss in STR
    QString netConvertDefaultKeepEdgesByVclass;

    // Remove edges which allow only vclasses from STR
    QString netConvertDefaultRemoveEdgesByVclass;

    // Only keep edges where type is in STR
    QString netConvertDefaultKeepEdgesByType;

    // Remove edges where type is in STR
    QString netConvertDefaultRemoveEdgesByType;

    // Removes isolated edges; default: false
    bool netConvertDefaultRemoveEdgesIsolated;

    // All nodes will be unregulated; default: false
    bool netConvertDefaultKeepNodesUnregulated;

    // Do not regulate nodes in STR
    QString netConvertDefaultKeepNodesUnregulatedExplicit;

    // Do not regulate district nodes; default: false
    bool netConvertDefaultKeepNodesUnregulatedDistrictNodes;

    // Continue on broken input; default: false
    bool netConvertDefaultIgnoreErrors;

    // Continue on invalid connections; default: false
    bool netConvertDefaultIgnoreErrorsConnections;

    // Show errors in connections at parsing; default: false
    bool netConvertDefaultShowErrorsConnectionsFirstTry;

    // Continue on unknown edge types; default: false
    bool netConvertDefaultIgnoreErrorsEdgeType;

    // The factor for flow to no. lanes conversion; default: 1800
    qreal netConvertDefaultLanesFromCapacityNorm;

    // vmax is parsed as given in km/h (some); default: false
    bool netConvertDefaultSpeedInKmh;

    // If edge shapes do not end at the node positions, extend them; default: false
    bool netConvertDefaultPlainExtendEdgeShape;

    // The edge lengths given in the MATSIMFile will be kept; default: false
    bool netConvertDefaultMatsimKeepLength;

    // The lane number will be computed from the capacity; default: false
    bool netConvertDefaultMatsimLanesFromCapacity;

    // Read edge ids from column STR
    QString netConvertDefaultShapefileStreetId;

    // Read fromNode ids from column STR
    QString netConvertDefaultShapefileFromId;

    // Read toNode ids from column STR
    QString netConvertDefaultShapefileToId;

    // Read type ids from column STR
    QString netConvertDefaultShapefileTypeId;

    // Uses edge type defaults on problems; default: false
    bool netConvertDefaultShapefileUseDefaultsOnFailure;

    // Insert edges in both directions; default: false
    bool netConvertDefaultShapefileAllBidirectional;

    // Guess the proper projection; default: false
    bool netConvertDefaultShapefileGuessProjection;

    // Structure join offset; default: 5
    qreal netConvertDefaultVissimJoinDistance;

    // Use FLOAT as default speed; default: 50
    qreal netConvertDefaultVissimDefaultSpeed;

    // Factor for edge velocity; default: 1
    qreal netConvertDefaultVissimSpeedNorm;

    //	Writes lanes without an explicit speed set; default: false
    bool netConvertDefaultVissimReportUnsetSpeeds;

    // Uses priorities from types; default: false
    bool netConvertDefaultVisumUseTypePriority;

    // Uses lane numbers from types; default: false
    bool netConvertDefaultVisumUseTypeLaneno;

    // Uses speeds from types; default: false
    bool netConvertDefaultVisumUseTypeSpeed;

    // Sets connector speed; default: 100
    qreal netConvertDefaultVisumConnectorSpeeds;

    // Sets connector lane number; default: 3
    int netConvertDefaultVisumConnectorsLaneNumber;

    // Excludes connectors; default: false
    bool netConvertDefaultVisumNoConnectors;

    // Computes the number of lanes from the edges' capacities; default: false
    bool netConvertDefaultVisumRecomputeLaneNumber;

    // Prints all warnings, some of which are due to VISUM misbehaviour; default: false
    bool netConvertDefaultVisumVerboseWarnings;

    // Skips the check for duplicate nodes and edges; default: false
    bool netConvertDefaultOsmSkipDuplicatesCheck;

    // Imports railway edges as oneWay by default; default: true
    bool netConvertDefaultOsmRailwayOnewayDefault;

    // Imports elevation data; default: false
    bool netConvertDefaultOsmElevation;

    // Imports all lane types; default: false
    bool netConvertDefaultOpendriveImportAllLanes;

    // Whether lane widths shall be ignored.; default: false
    bool netConvertDefaultOpendriveIgnoreWidths;

    // Omits internal links; default: false
    bool netConvertDefaultNoInternalLinks;

    // Removes vehicle class restrictions from imported edges; default: false
    bool netConvertDefaultDismissVclasses;

    // Disables building turnarounds; default: false
    bool netConvertDefaultNoTurnarounds;

    // Disables building turnarounds at tlsControlled junctions; default: false
    bool netConvertDefaultNoTurnaroundsTls;

    // Disables building connections to left; default: false
    bool netConvertDefaultNoLeftConnections;

    // Splits edges across geometry nodes; default: false
    bool netConvertDefaultGeometrySplit;

    // Replace nodes which only define edge geometry by geometry points (joins edges); default: false
    bool netConvertDefaultGeometryRemove;

    // splits geometry to restrict segment length; default: 0
    qreal netConvertDefaultGeometryMaxSegmentLength;

    // reduces too similar geometry points
    qreal netConvertDefaultGeometryMinDist;

    // Warn about edge geometries with an angle above DEGREES in successive segments; default: 99
    qreal netConvertDefaultGeometryMaxAngle;

    // Warn about edge geometries with a turning radius less than METERS at the start or end; default: 9
    qreal netConvertDefaultGeometryMinRadius;

    // Straighten edge geometries to avoid turning radii less than geometryMinRadius; default: false
    bool netConvertDefaultGeometryMinRadiusFix;

    // Warn if the junction shape is to far away from the original node position; default: 20
    qreal netConvertDefaultGeometryJunctionMismatchThreshold;

    // Turn off normalizing node positions; default: false
    bool netConvertDefaultOffsetDisableNormalization;

    // Adds FLOAT to net xPositions; default: 0
    qreal netConvertDefaultOffsetX;

    // Adds FLOAT to net yPositions; default: 0
    qreal netConvertDefaultOffsetY;

    // Flips the yCoordinate along zero; default: false
    bool netConvertDefaultFlipYAxis;

    // Enable roundaboutGuessing; default: false
    bool netConvertDefaultRoundaboutsGuess;

    // Assumes left-hand traffic on the network; default: false
    bool netConvertDefaultLefthand;

    // Joins junctions that are close to each other (recommended for OSM import); default: false
    bool netConvertDefaultJunctionsJoin;

    // Determines the maximal distance for joining junctions (defaults to 10); default: 10
    qreal netConvertDefaultJunctionsJoinDist;

    // Interprets STR as list of junctions to exclude from joining
    QString netConvertDefaultJunctionsJoinExclude;

    // Modifies all edge speeds by adding FLOAT; default: 0
    qreal netConvertDefaultSpeedOffset;

    // Modifies all edge speeds by multiplying by FLOAT; default: 1
    qreal netConvertDefaultSpeedFactor;

    // Generate INT intermediate points to smooth out intersection corners; default: 0
    int netConvertDefaultJunctionsCornerDetail;

    // Allow driving onto a multiLane road if there are foes on other lanes (at roundabouts); default: true
    bool netConvertDefaultCheckLaneFoesRoundabout;

    // Allow driving onto a multiLane road if there are foes on other lanes (everywhere); default: false
    bool netConvertDefaultCheckLaneFoesAll;

    // Guess pedestrian sidewalks based on edge speed; default: false
    bool netConvertDefaultSidewalksGuess;

    // Add sidewalks for edges with a speed equal or below the given limit; default: 13.89
    qreal netConvertDefaultSidewalksGuessMaxSpeed;

    // Add sidewalks for edges with a speed above the given limit; default: 5.8
    qreal netConvertDefaultSidewalksGuessMinSpeed;

    // Add sidewalks for edges that allow pedestrians on any of their lanes regardless of speed; default: false
    bool netConvertDefaultSidewalksGuessFromPermissions;

    // Guess pedestrian crossings based on the presence of sidewalks; default: false
    bool netConvertDefaultCrossingsGuess;

    // Determines the maximal distance for joining traffic lights (defaults to 20); default: 20
    qreal netConvertDefaultTlsJoinDist;

    // Interprets tls nodes surrounding an intersection as signal positions for a larger TLS. This is typical pattern for OSMDerived networks; default: false
    bool netConvertDefaultTlsGuessSignals;

    // Distance for interpreting nodes as signal locations; default: 25
    qreal netConvertDefaultTlsGuessSignalsDist;

    // The default number of lanes in an edge; default: 1
    int netConvertDefaultDefaultLanenumber;

    // The default speed on an edge (in m/s); default: 13.9
    qreal netConvertDefaultDefaultSpeed;

    // The default priority of an edge; default: -1
    int netConvertDefaultDefaultPriority;

    // The default width of added sidewalks; default: 2
    qreal netConvertDefaultDefaultSidewalkWidth;

    // Switches to verbose output; default: false
    bool netConvertDefaultVerbose;

    // Prints option values before processing; default: false
    bool netConvertDefaultPrintOptions;

    // Prints this screen; default: false
    bool netConvertDefaultHelp;

    // Prints the current version; default: false
    bool netConvertDefaultVersion;

    // Set schema validation scheme of XML inputs ("never", "auto" or "always"); default: auto
    QString netConvertDefaultxmlValidation;

    // Disables output of warnings; default: false
    bool netConvertDefaultNoWarnings;

    // Writes all messages to FILE (implies verbose)
    QString netConvertDefaultLog;

    // Writes all nonError messages to FILE (implies verbose)
    QString netConvertDefaultMessageLog;

    // Writes all warnings and errors to FILE
    QString netConvertDefaultErrorLog;

    // Initialises the random number generator with the current system time; default: false
    bool netConvertDefaultRandom;

    //Initialises the random number generator with the given value; default: 23423
    int netConvertDefaultSeed;
};

#endif // NETCONVERTCONFIGURATION_H
