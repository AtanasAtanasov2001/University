<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <board-game-store>
            <xsl:for-each select="board-game-store/game">
                <game>
                    <xsl:call-template name="game-title"/>
                    <xsl:call-template name="publisher"/>
                    <xsl:call-template name="still-playing"/>
                </game>
            </xsl:for-each>
        </board-game-store>
    </xsl:template>

    <xsl:template name="game-title">
        <code>
            <xsl:value-of select="id"/>
        </code>
        <title>
            <xsl:value-of select="title"/>
        </title>
    </xsl:template>

    <xsl:template name="publisher">
        <publisher isin="{publisher/@isin}">
            <name>
                <xsl:value-of select="publisher/name"/>
            </name>
            <country>
                <xsl:value-of select="publisher/headquarters/country"/>
            </country>
        </publisher>
    </xsl:template>

    <xsl:template name="still-playing">
        <still-playing present="{still-playing/@present}"/>
    </xsl:template>

</xsl:stylesheet>
