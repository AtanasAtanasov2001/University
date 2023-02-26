<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <game_library>
            <xsl:for-each select="game_library/game">
                <game>
                    <xsl:call-template name="game-name"/>
                    <game-summary>
                        <xsl:call-template name="game-summary"/>
                    </game-summary>
                    <game-publisher>
                        <xsl:call-template name="game-publisher"/>
                    </game-publisher>
                </game>
            </xsl:for-each>
        </game_library>
    </xsl:template>

    <xsl:template name="game-name">
        <code>
            <xsl:value-of select="id"/>
        </code>
        <name>
            <xsl:value-of select="game_name"/>
        </name>
    </xsl:template>

    <xsl:template name="game-summary">
        <xsl:value-of select="summary"/>
    </xsl:template>

    <xsl:template name="game-publisher">
        <xsl:value-of select="publisher"/>
    </xsl:template>

</xsl:stylesheet>
