<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <game_library>
            <xsl:for-each select="game_library/game">
                <game>
                    <xsl:call-template name="game-name"/>
                    <game-rating>
                        <xsl:call-template name="game-rating"/>
                    </game-rating>
                    <game-genres>
                        <xsl:call-template name="game-genres-genre-name"/>
                    </game-genres>
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

    <xsl:template name="game-rating">
        <xsl:value-of select="rating"/>
    </xsl:template>

    <xsl:template name="game-genres-genre-name">
        <xsl:value-of select="genres/genre/@name"/>
    </xsl:template>

</xsl:stylesheet>
